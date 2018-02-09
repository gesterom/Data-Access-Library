#include <iostream>
#include "../headers/Encja.h"
#include "../headers/Factory.h"

int main( int argv, char** args ) {

	//Factory f();
	Loader<int> l;
	Updater<int> u("lolitka");
	Encja<int> mojaencja(&l,&u);
	//Factory f;
	Encja<int> a;
	//std::cin>>mojaencja;
	std::cout<<mojaencja<<std::endl;;
	//std::cout<<std::endl;
	//Encja<int> enc = fac.load();
	//std::cin>>enc;
	//std::cout<<enc*10<<std::endl;

	return 0;
}
