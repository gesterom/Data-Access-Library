#include <iostream>
#include "ByteOperations.h"

#define DBG(x) {//std::cout<<#x<<"\t["<<x<<"]\n";}

template <>
class Loader <int> {
	int value;
	int alabama;
	public:
	Loader(){
		//std::cout<<"Loader crt"<<std::endl;
		value= 0x67452301;
		//DBG(value);
		alabama= 0xefcdab89;
		//DBG(alabama);
	}
	int * load(){
	//std::cout<<"Loader load uesed"<<std::endl;
	//std::cout<<"000 : loader mem [ "<<ptrToString((char*)this,sizeof(Loader<int>))<<" ]"<<std::endl;
	//std::cout<<value<<" < value "<<std::endl;
	return new int;
	}
	~Loader(){
		//std::cout<<"@@@ : loader mem [ "<<ptrToString((char*)this,sizeof(Loader<int>))<<" ]"<<std::endl;
	}
};

template <>
class Loader <char> {
	int value;
	char a;
	public:
	Loader(){
		value= 0x12345678;
		//DBG(value);
		a= 0x42;
		//DBG(a);
	}
	int * load(){return &value;}
};
