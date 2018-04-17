#pragma once

template<typename Type>
class Reference final {
  public:
	//constructors
	Reference();
	Reference<Type>& init( IAccessOperator<Type>* access);
	Reference( IAccessOperator<Type>* loader);
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
	IAccessOperator<Type>* access;
	bool	haveObject = false;
	static Manager<Type> manager;
};

template<typename Type>
Manager<Type> Reference<Type>::manager;
