#pragma once
#include "Exeptions.h"
#include <stdint.h>

template<typename Type>
class Object final{
	public:
	Object();
	virtual ~Object();
	int32_t incrementReferenceNumber();
	int32_t decrementReferenceNumber();
	Type& get(){ throw new NotImplemented("Object");}
	bool operator==(Object<Type> & right) const{
		return (*this)==right;
	}
	private:
};
