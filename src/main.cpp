#include <iostream>
#include "../include/Reference.h"
#include "../include/Hash.h"

int main(int argv, char** args){
	//std::cout<<"===================================================="<<std::endl;
	Loader<int> * l = new Loader<int>();
	//std::cout<<"===================================================="<<std::endl;
	Reference<int> ref(l);
	//std::cout<<"===================================================="<<std::endl;
	std::cin>>ref;
	//std::cout<<"===================================================="<<std::endl;
	std::cout<<ref<<std::endl;	
	//std::cout<<"===================================================="<<std::endl;
}
