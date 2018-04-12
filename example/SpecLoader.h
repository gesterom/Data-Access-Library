#pragma once
#include "../DAL/DAL.h"
#include <fstream>
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
	virtual DAL::ILoader<Type> * getCopyPtr()const{
		std::cout<<"not implemented"<<std::flush<<std::endl;
		throw new DAL::NotImplemented("ILoader =====");
	}
};

template <typename Type>
class Updater: public DAL::IUpdater<Type>
{
	public:
	Updater(){}
	virtual void update(Type&){}
	virtual DAL::IUpdater<Type> * getCopyPtr()const{}
};

template <>
class Loader <int> : public DAL::ILoader<int>
{
	std::string name;
	public:
	Loader(std::string filename) : name(filename){}
	Loader(const Loader<int> & other){
		this->name = other.name;
	}
	virtual int * load() override {
		std::ifstream file(name);
		int * temp = new int;
		file>>*temp;
		return temp;
	}
	virtual DAL::ILoader<int>* getCopyPtr()const{
		return new Loader<int>(name);
	}
	virtual std::string toString() override {
		return "0";
	}
	virtual ~Loader(){
	}
};

template <>
class Updater<int> : public DAL::IUpdater<int>
{
	std::string name;
	public:
	Updater(std::string filename) : name(filename) {}
	virtual void update(int & a) {
		std::ofstream file(name);
		file<<a;
	} 
	virtual IUpdater<int> * getCopyPtr()const{
		return new Updater(name);
	}
};
