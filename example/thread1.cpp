#include <thread>
#include <chrono>
#include "../DAL/DAL.h"
#include "SpecLoader.h"

int func1(){
	try{
		DAL::ILoader<int> * l = new Loader<int>();
		DAL::Reference<int> ref(l);
		ref.get()=15;
		std::cout<<"func 1:) I hava a obj :) ref = "<<ref<<std::endl;
		std::cout<<"func 1: i wait"<<std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 0;
	}
	catch(DAL::ThisIsNotPossible * e){
		std::cout<<"============================"<<e->get()<<std::endl<<"============================"<<std::endl;
		return -1;
	}
}

int func2(){
	try{
		DAL::ILoader<int> * l = new Loader<int>();
		DAL::Reference<int> ref(l);
		ref.get()+=255;
		std::cout<<"func1 and func2 have the same loader so Reference<int> points the same int"<<std::endl;
		std::cout<<"func 2:) I hava a obj :) ref = "<<ref<<std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		return 0;
	}
	catch(DAL::ThisIsNotPossible * e){
		std::cout<<"============================"<<e->get()<<std::endl<<"============================"<<std::endl;
		return -1;
	}
}


int main(){

	std::thread t1(func1);
	std::thread t2(func2);

	t1.join();
	t2.join();	



	std::cout<<"end thread section"<<std::endl;
	func1();
	func2();
	std::cout<<"end"<<std::endl;
	return 0;
}
