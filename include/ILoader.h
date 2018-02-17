#pragma once

template<typename Type>
class ILoader{
	public:
	ILoader(){}
	virtual Type * load(){
		std::string error = "Loader<";
		error = error + typeid(Type).name()+"> is not implmented. load()";
		throw new NotImplemented(error);
	}
	virtual ~ILoader(){}
};
