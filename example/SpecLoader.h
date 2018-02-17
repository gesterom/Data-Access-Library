#pragma once
#include "../include/DAL.h"

template <typename Type>
class Loader : public DAL::ILoader<Type>
{
	public:
	Loader(){}
	virtual Type* load() override{
		throw new int;
	}
};

template <>
class Loader <int> : public DAL::ILoader<int>
{
	int value;
	int alabama;
	public:
	Loader(){
		value= 0x67452301;
		alabama= 0xefcdab89;
	}
	virtual int * load() override {return new int;}
	~Loader(){
	}
};

template <>
class Loader <char> {
	int value;
	char a;
	public:
	Loader(){
		value= 0x12345678;
		a= 0x42;
	}
	virtual char * load(){return new char;}
};
