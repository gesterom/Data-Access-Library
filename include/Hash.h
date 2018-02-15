#pragma once
#include <functional>
#include <string>

#include "Loader.h"
#include "ByteOperations.h"

template<typename Type>
class LoaderHasher{
	public:
	LoaderHasher(){}
	std::size_t operator() (Loader<Type> const & l) const{
		char * ptr = new char[sizeof(Loader<Type>)];
		memcpy(ptr,&l,sizeof(Loader<Type>));
		std::string ret = ptrToString(ptr,sizeof(Loader<Type>));
		delete[] ptr;
		size_t r = std::hash<std::string>{}(ret);
		return r;
	}

};


