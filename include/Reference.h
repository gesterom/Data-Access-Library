#pragma once
#include "Object.h"
#include "Loader.h"
#include "Manager.h"



template<typename Type>
class Reference final{
	public:
	Reference(Loader<Type> * loader){
		this->loader = loader;
		std::cout<<"Reference = incrementReferenceNumber\n";
		this->manager.incrementReferenceNumber(*loader);
	}
	operator Type&() {
	std::cout<<typeid(Type).name()<<"&\t Reference\n";
	std::cout<<"XXX : loader mem [ "<<ptrToString((char*)loader,sizeof(Loader<int>))<<" ] ADRESS: {"<<uint64_t(loader)<<" }"<<std::endl;
		if(not used){
		std::cout<<"Reference = Not used\n";
			used=true;
			this->object = manager.getObject(*this->loader);
			std::cout<<"Reference = manager\n";
		}
		std::cout<<"Reference = ret\n";
		std::cout<<"XXX : loader mem [ "<<ptrToString((char*)loader,sizeof(Loader<int>))<<" ] ADRESS: {"<<uint64_t(loader)<<" }"<<std::endl;
		return this->object->get();
	}
	~Reference(){
		if(used){
			object->unlockMutex();
		}
		manager.decrementReferenceNumber(*loader);
		delete loader;
	}
	private:
	Object<Type> * object;
	Loader<Type> * loader;
	bool	used=false;
	static Manager<Type> manager; //FIXME ?
};

template<typename Type>
Manager<Type> Reference<Type>::manager;
