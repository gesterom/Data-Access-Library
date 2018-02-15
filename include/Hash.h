#pragma once
#include <functional>
#include <cstring>
#include <string>
#include <iostream>
#include <stdint.h>

#include "Loader.h"

std::string getHex(uint8_t v){
	char tabel[] = "0123456789ABCDEF";
	std::string ret;
	ret = tabel[v>>4];
	ret+= tabel[v%16];
	return ret;
}

std::string ptrToString(char * ptr , int size){
	std::string ret;
	for(int i=0;i<size;i++){
		ret += getHex((uint8_t)ptr[i]);
	}
	return ret;
}

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


