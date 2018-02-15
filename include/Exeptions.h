#pragma once
#include <string>

class NotImplemented{
	std::string msg;
	public:
	NotImplemented(std::string name) : msg(name){}
	std::string get(){return msg;}
};
class FactoryImplemented{};
class NullReferenceExeption{};
class ThisIsNotPossible{};

