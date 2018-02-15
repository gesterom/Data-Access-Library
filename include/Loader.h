#pragma once

#include "ByteOperations.h"

template<typename Type>
class Loader final{
	public:
	Loader(){}
	Type * load();
	~Loader(){}
};

template<typename Type>
bool operator==(const Loader<Type> & left, const Loader<Type> & right){
	return hardByteEqual((char*)&left,(char*)&right,sizeof(Loader<Type>));
}

#include "SpecLoader.h"
