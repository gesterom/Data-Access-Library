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
