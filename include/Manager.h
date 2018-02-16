#pragma once
#include "Loader.h"
#include "Object.h"
#include "Hash.h"

#include <unordered_map>

template<typename Type>
class Manager final{
	public:
	Manager(){}
	Object<Type> * getObject(Loader<Type> & loader){
		auto it = map.find(loader);
		if(it==map.end()){
			throw new ThisIsNotPossible("getObject");
		}
		if(not map[loader]->isLoaded()){
			std::cout<<"2 : loader mem [ "<<ptrToString((char*)&loader,sizeof(Loader<Type>))<<" ]"<<std::endl;
			map[loader]->setRawPointer(loader.load());
			std::cout<<"3 : loader mem [ "<<ptrToString((char*)&loader,sizeof(Loader<Type>))<<" ]"<<std::endl;
		}
		return map[loader];
	}
	void incrementReferenceNumber(Loader<Type> & loader){
		std::cout<<"1 : loader mem [ "<<ptrToString((char*)&loader,sizeof(Loader<Type>))<<" ]"<<std::endl;
		auto it = map.find(loader);
		if(it==map.end()){
			std::cout<<"Manager = crt new OBJ"<<std::endl;
			map[loader] = new Object<Type>();
		}
		it = map.find(loader);
		if(it!=map.end()){
			std::cout<<"Manager =  secoond check"<<std::endl;
		}
		
		std::cout<<"Manager =  incrementReferenceNumber\n";
		map[loader]->incrementReferenceNumber();
	}
	void decrementReferenceNumber(Loader<Type> & loader){
	std::cout<<"4 : loader mem [ "<<ptrToString((char*)&loader,sizeof(Loader<Type>))<<" ]"<<std::endl;
		auto it = map.find(loader);
		if(it==map.end()){
			for(int i=0;i<map.size();i++){
				std::cout<<i<<std::endl;
			}
			throw new ThisIsNotPossible("Manager = decrementReferenceNumber");
		}
		if(map[loader]->decrementReferenceNumber()==0){
			std::cout<<"Manager = I delete obj\n";
			delete map[loader];
		}
		
	}
	virtual ~Manager(){}
	private:
	std::unordered_map< Loader<Type> , Object<Type>* , LoaderHasher<Type>> map;
};
