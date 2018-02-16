#pragma once
#include <stdint.h>
#include <cstring>
#include <string>

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
bool hardByteEqual(char * left,char * right, uint64_t size){
	char * lptr = new char[size];
	memcpy(lptr,left,size);
	std::string sleft = ptrToString(lptr,size);
	
	char * rptr = new char[size];
	memcpy(rptr,right,size);
	std::string sright = ptrToString(rptr,size);
	delete[] rptr;
	delete[] lptr;
	return sleft==sright;

}

