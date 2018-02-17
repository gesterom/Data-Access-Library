#pragma once

template<typename Type>
class Loader final{
	public:
	Loader(){}
	Type * load();
	~Loader(){}
};
