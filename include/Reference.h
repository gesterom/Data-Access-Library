#pragma once
#include "Object.h"
#include "Loader.h"
#include "Manager.h"

template<typename Type>
class Reference final{
	public:
	Reference(Loader<Type> * loader){
		this->loader = loader;
	}
	operator Type&() {
		this->object = manager.getObject(this->loader);
		return this->object->get();
	}
	virtual ~Reference(){}
	private:
	Object<Type> * object;
	Loader<Type> * loader;
	static Manager<Type> manager; //FIXME ?
};

template<typename Type>
Manager<Type> Reference<Type>::manager;
