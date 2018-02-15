#include <iostream>

#define DBG(x) {std::cout<<#x<<"\t["<<x<<"]\n";}

template <>
class Loader <int> {
	int value;
	int alabama;
	public:
	Loader(){
		value= 0x01234567;
		//DBG(value);
		alabama= 0xfedcba98;
		//DBG(alabama);
	}
	int * load(){return &value;}
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
