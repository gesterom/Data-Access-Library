#pragma once
#include <string>
#include <iostream>

class NotImplemented{
	std::string msg;
	public:
	NotImplemented(std::string name) : msg(name){}
	std::string get(){return msg;}
};
class FactoryImplemented{};
class NullReferenceExeption{};
class ThisIsNotPossible{
	std::string msg;
	public:
	ThisIsNotPossible(std::string name) : msg(name){
	std::cout<<msg<<std::endl;}
	std::string get(){return msg;}
};

