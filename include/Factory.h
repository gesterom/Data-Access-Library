#include <iostream>
#include "Reference.h"
#include "Exeptions.h"
#pragma once

template<typename Type>
class Factory
{
	public:
		Factory ();
		Reference<Type> createNewReference(...){ throw new FactoryImplemented();}
		virtual ~Factory ();

	private:
		/* data */
};
