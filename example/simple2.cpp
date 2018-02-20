#include <iostream>
#include "../DAL/DAL.h"
#include "SpecLoader.h"
#include <memory>
#include <vector>
#include <algorithm>

int main()
{
	DAL::Reference<int> r{new Loader<int>}; 
	std::vector<DAL::Reference<int>> references;
	DAL::Reference<int> b = r;
	return 0;
}