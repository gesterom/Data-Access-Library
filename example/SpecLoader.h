#pragma once
#include "../DAL/DAL.h"
#include <fstream>
template <typename Type>
class Loader{};

template <typename Type>
class Updater{};

template <>
class Loader <int> : public DAL::ILoader<int> {
	std::string name;
  public:
	Loader( std::string filename ) : name( filename ) {}
	Loader( const Loader<int>& other ) {
		this->name = other.name;
	}
	virtual int* load() override {
		std::ifstream file( name );
		int* temp = new int;
		file >> *temp;
		return temp;
	}
	virtual DAL::ILoader<int>* getCopyPtr()const {
		return new Loader<int>( name );
	}
	virtual std::string toString() override {
		return name;
	}
	virtual ~Loader() {
	}
};

template <>
class Updater<int> : public DAL::IUpdater<int> {
	std::string name;
  public:
	Updater( std::string filename ) : name( filename ) {}
	virtual void update( int& a ) {
		std::ofstream file( name );
		file << a;
	}
	virtual IUpdater<int>* getCopyPtr()const {
		return new Updater( name );
	}
};
