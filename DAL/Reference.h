#pragma once

template<typename Type>
class Reference final {
  public:
	//constructors
	Reference();
	Reference<Type>& init( ILoader<Type>* loader, IUpdater<Type>* updater );
	Reference( ILoader<Type>* loader, IUpdater<Type>* updater );
	Reference( const Reference<Type>& other );
	Reference( Reference<Type>&& other );
	Reference<Type>& operator=( const Reference<Type>& other );
	Reference<Type>& operator=( Reference<Type>&& other );

	//geters
	Type& get();
	Type* operator->();
	Type& operator*();
	operator Type& () ;

	//operators


	~Reference();

	//members
  private:
	Object<Type>* object;
	ILoader<Type>* loader;
	IUpdater<Type>* updater;
	bool	haveObject = false;
	static Manager<Type> manager;
};

template<typename Type>
Manager<Type> Reference<Type>::manager;
