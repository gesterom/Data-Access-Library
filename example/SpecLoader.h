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
	virtual std::string toString(){
		std::cout<<"not implemented"<<std::flush<<std::endl;
		throw new DAL::NotImplemented("Loader toString");
	}
	virtual void operator=(Loader<int> & other){
			std::cout<<"not implemented"<<std::flush<<std::endl;
		throw new DAL::NotImplemented("Loader =====");
	}
};

template <>
class Loader <int> : public DAL::ILoader<int>
{
	int value;
	int alabama;
	public:
	Loader(){
		//std::cout<<"LOADER RAW : {"<<__FUNCTION__<<"} : "<<DAL::ptrToString((char*)this,sizeof(*this))<<std::endl;
		value= 0xAAAABBBB;
		alabama= 0xefcdab89;
		//std::cout<<"LOADER RAW : {"<<__FUNCTION__<<"} : "<<DAL::ptrToString((char*)this,sizeof(*this))<<std::endl;
	}
	Loader(const Loader<int> & other){
		//std::cout<<"LOADER RAW : {"<<__FUNCTION__<<"} : "<<DAL::ptrToString((char*)this,sizeof(*this))<<std::endl;
		this->value = other.value;
		this->alabama = other.alabama;
		//std::cout<<"LOADER RAW : {"<<__FUNCTION__<<"} : "<<DAL::ptrToString((char*)this,sizeof(*this))<<std::endl;
	}
	virtual int * load() override {return new int;}
	virtual void operator=(Loader<int> & other){
		//std::cout<<"LOADER RAW : {"<<__FUNCTION__<<"} : "<<DAL::ptrToString((char*)this,sizeof(*this))<<std::endl;
		this->value = other.value;
		this->alabama = other.alabama;
		//std::cout<<"LOADER RAW : {"<<__FUNCTION__<<"} : "<<DAL::ptrToString((char*)this,sizeof(*this))<<std::endl;
	}
	virtual std::string toString() override {
		//std::cout<<"powinno działać"<<std::flush<<std::endl;
		return "0";
	}
	virtual ~Loader(){
	}
};
