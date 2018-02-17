#include <iostream>

#define SPECIALIZED_LOADERS_HEADER "SpecLoader.h"

#include "../include/DAL.h"

int main(){
	DAL::Loader<int> * l = new DAL::Loader<int>();
	DAL::Reference<int> ref(l);
	std::cout<<"Pleas enter a number : ";
	std::cin>>ref;
	std::cout<<"Your number is : "<<ref<<std::endl;
}
