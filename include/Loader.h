#pragma once

template<typename Type>
class Loader final{
	public:
	Loader(){
		std::string error = "Loader<";
		error = error + typeid(Type).name()+"> is not implmented. constructor()";
		throw new NotImplemented(error);
	}
	Type * load(){
		std::string error = "Loader<";
		error = error + typeid(Type).name()+"> is not implmented. load()";
		throw new NotImplemented(error);
	}
	~Loader(){}
};
