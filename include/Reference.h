#pragma once
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <stdint>
#include "./Exeptions.h"

//This template must be specialized in saving changes to the object referenced by the reference
//Save the changes in the real object
template<typename Type>
class Updater{
	public:
	void update(Type & data) {throw new NotImplemented();}
	Updater(){}
};

//Parameterized and encapsulated invocation of the constructor in the object
template<typename Type>
class Loader{
	public:
	Type * load(){throw new NotImplemented();}
};

template<typename Type>
class Object{
	std::mutex my_mutex;
	int32_t numberOfReferences;
	Type * data;
	public:
	Object(){ numberOfReferences=0; }
	Type & get(){ return *(this->data);}
	void incrementReferenceNumber(){ this->numberOfReferences++;}
	void decrementReferenceNumber(){ 
		this->numberOfReferences--;
		if(numberOfReferences<=0){
			delete this; //FIXME ?
		}
	}
	virtual ~Object(){
		
	}
	
	
};

template<typename Type>
class Reference {

	private:
	Object<Type> & data; 
	Updater<Type> * updater;
	Loader<Type> * loader;
	bool used = false;
	Manager<Type> & manager;
	protected:
	public:
		Reference(Loader<Type> * m_loader,Updater<Type> * m_updater){
			this->loader = m_loader;
			this->updater = m_updater;
			
			this->manager->incrementReferenceNumber(*loader);
			
		}
		operator Type&(){
			if(not used){
				this->data = this->manager->load(*loader);
				this->used = true;
			}
			return *(this->data);
		}
		Reference( const Reference& other); // copy constructor
		Reference( const Reference&& other); // move constructor
		Reference& operator=( const Reference& other); // copy assignment
		Reference& operator=( const Reference&& other); // move assignment


	virtual ~Reference(){
		updater->update(*data);
		
		this->manager->decrementReferenceNumber(*loader);
		
		delete updater;
		delete loader;
	}

};



template<typename Type>
class Manager{
	public:
	void decrementReferenceNumber(Loader<Type> & loader);
	void incrementReferenceNumber(Loader<Type> & loader);
	void load(Loader<Type> & loader);
};





