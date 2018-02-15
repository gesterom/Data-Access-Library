#pragma once
#include "Loader.h"
#include "ByteOperations.h"

template <typename Type>
class Equal
{
	bool operator==(const Loader<Type> & left,const Loader<Type> & right) const{
		return hardByteEqual(&left,&right,sizeof(Loader<Type>));
	}
};
