#include <iostream>
#define SPECIALIZED_LOADERS_HEADER "../include/SpecLoader.h"
#include "../include/DAL.h"

int main(int argv, char** args){
	DAL::Loader<int> * l = new DAL::Loader<int>();
	DAL::Reference<int> ref(l);
	std::cin>>ref;
	std::cout<<ref<<std::endl;
}
