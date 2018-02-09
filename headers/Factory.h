#include <iostream>
#include "Encja.h"
#include "Exeptions.h"
#pragma once

template<typename Type>
class Factory
{
	public:
		Factory ();
		Encja<Type> createNewReference(...){ throw new FactoryImplemented();}
		virtual ~Factory ();

	private:
		/* data */
};

template<>
Encja<int> Factory<int>::createNewReference(int v){
	int value;
	std::cout<<"I am factory and create int : "<<value<<std::endl;
	Encja<int> ret;
	return ret;
};
