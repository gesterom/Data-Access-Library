#pragma once

template<typename Type>
class Reference final{
	public:
	Reference(ILoader<Type> * loader);
	operator Type&() ;
	~Reference();
	private:
	Object<Type> * object;
	ILoader<Type> * loader;
	bool	used=false;
	static Manager<Type> manager; //FIXME ?
};

template<typename Type>
Manager<Type> Reference<Type>::manager;