#pragma once
#include <iostream>
#include "./Exeptions.h"


template<typename Type>
class Updater{
	public:
	virtual void update( Type data) = 0;
	Updater(){
		
	}
};

template<>
class Updater <int>
{
	std::string name;
	public:
	void update(int data){
		std::cout<<"I sava one int. Value : "<<data<<" My name is : "<<name<<std::endl;
	}
	Updater(std::string m_name){
		this->name = m_name;
	}
	Updater(){
		this->name = "default";
	}
};

template<typename Type>
class Loader{
	public:
	Type * load(){throw new NotImplemented();}
	Loader(){
		
	}
};

template<>
class Loader <int>
{
	public:
	std::istream& iss;
	int * ret;
	int * load(){
		if(ret)
			return ret;
			
		int t;
		std::cin>>t;
		int * ret = new int;
		*ret = t;
		std::cout<<"loaaaaaad...\n";
		return ret;
	}
	Loader(std::istream& m_iss = std::cin) : iss(m_iss){
		std::cout<<"load...\n";
		ret=0;
	}
	Loader(int v) : iss(std::cin){
		ret= new int;
		*ret = v;
	}
};

template<typename Type>
class Encja {

	private:
	Type * data;
	Updater<Type> * updater;
	protected:
	public:
		Encja(Loader<Type> * m_loader = new Loader<Type>(),Updater<Type> * m_updater = new Updater<Type>()){
			std::cout<<"lol"<<std::endl;
			this->data = m_loader->load();
			this->updater = m_updater;
		}
		operator Type&(){
			return *(this->data);
		}
		Encja( const Encja& other); // copy constructor
		Encja( const Encja&& other); // move constructor
		Encja& operator=( const Encja& other); // copy assignment
		Encja& operator=( const Encja&& other); // move assignment


	virtual ~Encja(){
		updater->update(*data);
		std::cout<<"samo zło"<<std::endl;
		delete data;
	}

};
