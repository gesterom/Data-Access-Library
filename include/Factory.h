#pragma once
#include "Exeptions.h"

template<typename Type>
class Factory{
	public:
	Reference<Type> createNewReferenc(...){throw new NotImplemented("Factory");};
	Factory(); //FIXME ?
};
