#pragma once
#include <iostream>
#include "./Exeptions.h"


template<typename Type>
class Updater{
	public:
	void update(Type * data) {throw new NotImplemented();}
	Updater(){}
};
template<typename Type>
class Loader{
	public:
	Type * load(){throw new NotImplemented();}
};
template<typename Type>
class Encja {

	private:
	Type * data;
	Updater<Type> * updater;
	Loader<Type> * loader;
	bool used = false;
	protected:
	public:
		Encja(Loader<Type> * m_loader,Updater<Type> * m_updater){
			this->loader = m_loader;
			this->updater = m_updater;
		}
		operator Type&(){
			if(not used)
				this->data = this->loader->load();
			return *(this->data);
		}
		Encja( const Encja& other); // copy constructor
		Encja( const Encja&& other); // move constructor
		Encja& operator=( const Encja& other); // copy assignment
		Encja& operator=( const Encja&& other); // move assignment


	virtual ~Encja(){
		updater->update(*data);
		
		delete updater;
		delete loader;
		delete data;
	}

};
