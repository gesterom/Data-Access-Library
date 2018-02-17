#pragma once

template<typename Type>
class Reference final{
	public:
	Reference(ILoader<Type> * loader);
	operator Type&() ;
	void operator=(const Type & data);
	~Reference();
	private:
	Object<Type> * object;
	ILoader<Type> * loader;
	bool	used=false;
	std::mutex mMag;
	static Manager<Type> manager; //FIXME ?
};

template<typename Type>
Manager<Type> Reference<Type>::manager;