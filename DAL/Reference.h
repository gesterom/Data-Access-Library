#pragma once

template<typename Type>
class Reference final{
	public:
	Reference() = delete;
	Reference(ILoader<Type> * loader);
	//Reference(ILoader<Type> * loader,const Type& value);
	Reference(const Reference<Type> & other);
	operator Type&() ;
	Type & get();
	Reference<Type>& operator=(const Type & data);
	~Reference();
	private:
	Object<Type> * object;
	ILoader<Type> * loader;
	bool	haveObject=false;
	static Manager<Type> manager; //FIXME ?
};

template<typename Type>
Manager<Type> Reference<Type>::manager;