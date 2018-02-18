#pragma once
#include "../include/DAL.h"

template <typename Type>
class Loader : public DAL::ILoader<Type>
{
	public:
	Loader(){}
	Loader(const Loader<Type> & other){
		std::cout<<"not implemented"<<std::endl;
		throw new DAL::NotImplemented("Loader");
	}
	virtual Type* load() override{
		std::cout<<"not implemented"<<std::endl;
		throw new int;
	}
	virtual std::string toString()override{
		std::cout<<"not implemented"<<std::flush<<std::endl;
		throw new DAL::NotImplemented("Loader toString");
	}
	virtual DAL::ILoader<Type> * getNewPtrToCopyOfThisLader()const{
		std::cout<<"not implemented"<<std::flush<<std::endl;
		throw new DAL::NotImplemented("ILoader =====");
	}
};

template <>
class Loader <int> : public DAL::ILoader<int>
{
	int value;
	int alabama;
	public:
	Loader(){
		value= 0xAAAABBBB;
		alabama= 0xefcdab89;
	}
	Loader(const Loader<int> & other){
		this->value = other.value;
		this->alabama = other.alabama;
	}
	virtual int * load() override {return new int;}
	virtual DAL::ILoader<int>* getNewPtrToCopyOfThisLader()const{
		Loader<int> * ret = new Loader<int>();
		ret->value = this->value;
		ret->alabama=this->alabama;
		return ret;
	}
	virtual std::string toString() override {
		return "0";
	}
	virtual ~Loader(){
	}
};
