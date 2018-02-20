//imp

template<typename Type>
Reference<Type>::~Reference(){
	if(haveObject){
		object->unlockMutex();
	}
	manager.decrementReferenceNumber(*loader);
	delete loader;
}
template<typename Type>
Reference<Type>::operator Type&() {
	return this->get();
}

template<typename Type>
Reference<Type>::Reference(ILoader<Type> * loader){
	this->loader = loader;
	this->manager.incrementReferenceNumber(*loader);
}
template<typename Type>
Reference<Type>::Reference(const Reference<Type> & other){
	this->loader=other.loader->getNewPtrToCopyOfThisLader();
	this->manager.incrementReferenceNumber(*loader);
}
template<typename Type>
Type& Reference<Type>::get(){
	if(not haveObject){
		haveObject=true;
		this->object = manager.getObject(*this->loader);
		this->object->lockMutex();
	}
	return this->object->get();
}

template<typename Type>
Reference<Type>& Reference<Type>::operator=(const Type & data){
	if(this->loader==nullptr){
		throw new ThisIsNotPossible("Reference no have a loader");
	}
	this->get()=data;
	return *this;
}
template<typename Type>
Type* Reference<Type>::operator->(){
	return &(this->get());
}