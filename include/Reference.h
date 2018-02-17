#pragma once

template<typename Type>
class Reference final{
	public:
	Reference(Loader<Type> * loader);
	operator Type&() ;
	~Reference();
	private:
	Object<Type> * object;
	Loader<Type> * loader;
	bool	used=false;
	static Manager<Type> manager; //FIXME ?
};

template<typename Type>
Manager<Type> Reference<Type>::manager;