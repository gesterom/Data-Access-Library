#include <iostream>
#include "../DAL/DAL.h"
#include "SpecLoader.h"
#include <memory>
#include <vector>
#include <algorithm>

int main() {
	DAL::Reference<int> r{new Loader<int>( "sample2" ), new Updater<int>( "sample2" )};
	std::vector<DAL::Reference<int>> references;
	DAL::Reference<int> b = r;
	return 0;
}