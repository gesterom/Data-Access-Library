#include <iostream>

#include "../DAL/DAL.h"
#include "SpecLoader.h"

int main(){
	DAL::ILoader<int> * l = new Loader<int>();
	DAL::Reference<int> ref(l);
	std::cout<<"Pleas enter a number : ";
	std::cin>>ref;
	std::cout<<"Your number is : "<<ref<<std::endl;
}
