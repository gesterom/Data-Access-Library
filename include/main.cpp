#include <iostream>
#include "Reference.h"
#include "Hash.h"

int main(int argv, char** args){
	Loader<int> l;
	Reference<int> ref(&l);
	LoaderHasher<int> hs;
	std::cout<<hs(l)<<std::endl;
	Loader<char> c;
	LoaderHasher<char> hc;
	std::cout<<hc(c)<<std::endl;
	try{
	std::cin>>ref;
	std::cout<<ref;
	}
	catch(NotImplemented * n){
		std::cout<<n->get()<<std::endl;
	}
	//for(int i=0;i<argv;i++)
	//std::cout<<args[i]<<std::endl;
	
	return 0;
}
