//imp

template<typename Type>
Reference<Type>::Reference() {
	this->access = nullptr;
}
template<typename Type>
Reference<Type>& Reference<Type>::init( IAccessOperator<Type>* access ) {
	this->access = access;
	this->manager.incrementReferenceNumber( *access );
}
template<typename Type>
Reference<Type>::Reference( IAccessOperator<Type>* access) {
	this->access = access;
	this->manager.incrementReferenceNumber( *access );
}
//copy
template<typename Type>
Reference<Type>::Reference( const Reference<Type>& other ) {
	this->access = other.access->getCopyPtr();
	this->manager.incrementReferenceNumber( *access );
}
//move
template<typename Type>
Reference<Type>::Reference( Reference<Type>&& other ) {
	if(this!=&other){
		this->object = other.object;
		this->access = other.access;
		this->haveObject = other.haveObject;

		other.object = nullptr;
		other.access = nullptr;
		other.haveObject = false;
	}
}
//copy
template<typename Type>
Reference<Type>& Reference<Type>::operator=( const Reference<Type>& other ) {
	this->access = other.access->getCopyPtr();
	this->manager.incrementReferenceNumber( *access );
}
//move
template<typename Type>
Reference<Type>& Reference<Type>::operator=( Reference<Type>&& other ) {
	if(this!=&other){
		this->object = other.object;
		this->access = other.access;
		this->haveObject = other.haveObject;

		other.object = nullptr;
		other.access = nullptr;
		other.haveObject = false;
	}
}
//===============================================================================
//geters
template<typename Type>
Type& Reference<Type>::get() {
	if( access == nullptr ) {
		throw new NullReferenceException();
	}

	if( not haveObject ) {
		haveObject = true;
		this->object = manager.getObject( *access );
		this->object->lockMutex();
	}

	return this->object->get();
}
template<typename Type>
Type* Reference<Type>::operator->() {
	return &(this->get());
}
template<typename Type>
Type& Reference<Type>::operator*() {
	return this->get();
}
template<typename Type>
Reference<Type>::operator Type& () {
	return this->get();
}

//===============================================================================
//operators
/*
    template<typename Type>
    Reference<Type>& Reference<Type>::operator=(Type & data){
	if(this->loader==nullptr){
		throw new ThisIsNotPossible("Reference no have a loader");
	}
	this->get()=data;
	return *this;
    }
    template<typename Type>
    bool Reference<Type>::operator==(Type & data){
	return this->get()==data;
    }
    template<typename Type>
    Type& Reference<Type>::operator+=(Type & data){
	return this->get()+=data;
    }*/
//===============================================================================
template<typename Type>
Reference<Type>::~Reference() {
	if( haveObject ) {
		this->access->update( this->object->get() );
		object->unlockMutex();
	}

	manager.decrementReferenceNumber( *access );
	delete access;
}

