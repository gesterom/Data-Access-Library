#pragma once
#include "Exeptions.h"
#include <stdint.h>
#include <mutex>

template<typename Type>
class Object final{
	int32_t referenceNumber;
	Type * data;
	std::mutex m;
	bool loaded=false;
	public:
	Object(){ referenceNumber=0;}
	~Object(){ m.unlock();delete data;}
	int32_t incrementReferenceNumber(){return ++referenceNumber;}
	int32_t decrementReferenceNumber(){return --referenceNumber;}
	bool isLoaded(){
		return loaded;
	}
	void unlockMutex(){
		if(not loaded) 
			throw new ThisIsNotPossible("unlockMutex");
		m.unlock();
	}
	void setRawPointer(Type * dataPtr){
		if (loaded==true){
			throw new ThisIsNotPossible("setRawPointer");
		}
		loaded = true ;
		data=dataPtr;
	}
	Type& get(){
		//std::cout<<"object->get()\n";
		if(not loaded) { throw new NullReferenceExeption();}
		m.lock();
		//std::cout<<"ret obj get\n";
		return *data;
	}
};
