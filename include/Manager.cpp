//imp
template<typename Type>
void Manager<Type>::decrementReferenceNumber(ILoader<Type> & loader){
	std::lock_guard<std::mutex> lock(mMag);
	auto it = map.find(loader.toString());
	if(it==map.end()){
		throw new ThisIsNotPossible("Manager = decrementReferenceNumber");
	}
	if(map[loader.toString()]->decrementReferenceNumber()==0){
		delete map[loader.toString()];
		it = map.find(loader.toString());
		map.erase(it);
	}
	
}
template<typename Type>
void Manager<Type>::incrementReferenceNumber(ILoader<Type> & loader){
	std::lock_guard<std::mutex> lock(mMag);
	auto it = map.find(loader.toString());
	if(it==map.end()){
		map[loader.toString()] = new Object<Type>();
	}
	map[loader.toString()]->incrementReferenceNumber();
}
template<typename Type>
Object<Type> * Manager<Type>::getObject(ILoader<Type> & loader){
	std::lock_guard<std::mutex> lock(mMag);
	auto it = map.find(loader.toString());
	if(it==map.end()){
		throw new ThisIsNotPossible("getObject");
	}
	if(not map[loader.toString()]->isLoaded()){
		map[loader.toString()]->setRawPointer(loader.load());
	}
	return map[loader.toString()];
}
