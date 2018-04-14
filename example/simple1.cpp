#include <iostream>

#include "../DAL/DAL.h"
#include "SpecLoader.h"

int main() {
	DAL::ILoader<int>* l = new Loader<int>( "int" );
	DAL::IUpdater<int>* u = new Updater<int>( "int" );
	DAL::Reference<int> ref( l, u );

	std::cout << "Pleas enter a number : ";
	std::cin >> ref;
	std::cout << "Your number is : " << ref << std::endl;
}
