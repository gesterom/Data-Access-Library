#pragma once

template<typename Type>
class IFactory{
	public:
	Reference<Type> createNewReferenc(...)=0;
	IFactory(); //FIXME ?
};
