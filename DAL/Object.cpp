//imp
template<typename Type>
Type& Object<Type>::get() {
	if( not loaded ) {
		throw new NullReferenceException();
	}

	return *data;
}
template<typename Type>
void Object<Type>::setRawPointer( Type* dataPtr ) {
	if ( loaded == true ) {
		throw new ThisIsNotPossible( "setRawPointer" );
	}

	loaded = true ;
	data = dataPtr;
}
template<typename Type>
void Object<Type>::unlockMutex() {
	if( not loaded ) {
		throw new ThisIsNotPossible( "unlockMutex" );
	}

	if( referenceNumber == 0 ) {
		throw new ThisIsNotPossible( "NullReference" );
	}

	m.unlock();
}
template<typename Type>
void Object<Type>::lockMutex() {
	if( not loaded ) {
		throw new ThisIsNotPossible( "unlockMutex" );
	}

	if( referenceNumber == 0 ) {
		throw new ThisIsNotPossible( "NullReference" );
	}

	m.lock();
}

template<typename Type>
bool Object<Type>::isLoaded() {
	return loaded;
}
template<typename Type>
int32_t Object<Type>::incrementReferenceNumber() {
	return ++referenceNumber;
}
template<typename Type>
int32_t Object<Type>::decrementReferenceNumber() {
	return --referenceNumber;
}

template<typename Type>
Object<Type>::~Object() {
	/*DBG(m.unlock());*/delete data;
}

template<typename Type>
Object<Type>::Object() {
	referenceNumber = 0;
	data = nullptr;
}
