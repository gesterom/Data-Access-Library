#pragma once
#include "Loader.h"
#include "Object.h"
#include "Hash.h"

#include <unordered_map>

template<typename Type>
class Manager final{
	public:
	Manager(){}
	Object<Type> * getObject(Loader<Type> * loader){
		throw new NotImplemented("Manager");
	}
	virtual ~Manager(){}
	private:
	std::unordered_map< Loader<Type> , Object<Type>* , LoaderHasher<Type> > map;
};
