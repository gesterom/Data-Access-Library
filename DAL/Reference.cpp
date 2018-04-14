//imp

template<typename Type>
Reference<Type>::Reference() {
	this->object = nullptr;
	this->loader = nullptr;
}
template<typename Type>
Reference<Type>& Reference<Type>::init( ILoader<Type>* loader, IUpdater<Type>* updater ) {
	this->loader = loader;
	this->updater = updater;
	this->manager.incrementReferenceNumber( *loader );
}
template<typename Type>
Reference<Type>::Reference( ILoader<Type>* loader, IUpdater<Type>* updater ) {
	this->loader = loader;
	this->updater = updater;
	this->manager.incrementReferenceNumber( *loader );
}
//copy
template<typename Type>
Reference<Type>::Reference( const Reference<Type>& other ) {
	this->loader = other.loader->getCopyPtr();
	this->manager.incrementReferenceNumber( *loader );
}
//move
template<typename Type>
Reference<Type>::Reference( Reference<Type>&& other ) {
	this->object = other.object;
	this->loader = other.loader;
	this->haveObject = other.haveObject;

	other.object = nullptr;
	other.loader = nullptr;
	other.haveObject = false;
}
//copy
template<typename Type>
Reference<Type>& Reference<Type>::operator=( const Reference<Type>& other ) {
	this->loader = other.loader->getCopyPtr();
	this->manager.incrementReferenceNumber( *loader );
}
//move
template<typename Type>
Reference<Type>& Reference<Type>::operator=( Reference<Type>&& other ) {
	this->object = other.object;
	this->loader = other.loader;
	this->haveObject = other.haveObject;

	other.object = nullptr;
	other.loader = nullptr;
	other.haveObject = false;
}
//===============================================================================
//geters
template<typename Type>
Type& Reference<Type>::get() {
	if( loader == nullptr or updater == nullptr ) {
		throw new NullReferenceException();
	}

	if( not haveObject ) {
		haveObject = true;
		this->object = manager.getObject( *this->loader );
		this->object->lockMutex();
	}

	return this->object->get();
}
template<typename Type>
Type* Reference<Type>::operator->() {
	return &( this->get() );
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
		this->updater->update( this->object->get() );
		object->unlockMutex();
	}

	manager.decrementReferenceNumber( *loader );
	delete loader;
}

