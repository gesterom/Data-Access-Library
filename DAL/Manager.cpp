//imp
template<typename Type>
void Manager<Type>::decrementReferenceNumber( IAccessOperator<Type>& access ) {
	std::lock_guard<std::mutex> lock( mMag );
	auto it = map.find( access.toString() );

	if( it == map.end() ) {
		throw new ThisIsNotPossible( "Manager = decrementReferenceNumber" );
	}

	if( map[access.toString()]->decrementReferenceNumber() == 0 ) {
		delete map[access.toString()];
		it = map.find( access.toString() );
		map.erase( it );
	}

}
template<typename Type>
void Manager<Type>::incrementReferenceNumber( IAccessOperator<Type>& access ) {
	std::lock_guard<std::mutex> lock( mMag );
	auto it = map.find( access.toString() );

	if( it == map.end() ) {
		map[access.toString()] = new Object<Type>();
	}

	map[access.toString()]->incrementReferenceNumber();
}
template<typename Type>
Object<Type>* Manager<Type>::getObject( IAccessOperator<Type>& access ) {
	std::lock_guard<std::mutex> lock( mMag );
	auto it = map.find( access.toString() );

	if( it == map.end() ) {
		throw new ThisIsNotPossible( "getObject" );
	}
	if( not map[access.toString()]->isLoaded() ) {
		Type * t = access.load();
		map[access.toString()]->setRawPointer( t );
	}

	return map[access.toString()];
}
