#include <thread>
#include <chrono>
#include "../DAL/DAL.h"
#include "SpecLoader.h"

DAL::Reference<int> getRef() {
	std::mutex m;
	m.lock();
	DAL::Reference<int> ref( new Loader<int>( "th2.int" ), new Updater<int>( "th2.int" ) );
	m.unlock();
	return ref;
}

int func1() {
	try {
		auto ref = getRef();
		ref.get() = ref.get() * 10;
		std::cout << "func 1:) I hava a obj :) ref = " << ref << std::endl;
		std::cout << "func 1: i wait" << std::endl;
		std::this_thread::sleep_for( std::chrono::seconds( 5 ) );
		return 0;
	}
	catch( DAL::ThisIsNotPossible* e ) {
		std::cout << "============================" << e->get() << std::endl << "============================" << std::endl;
		return -1;
	}
}

int func2() {
	try {
		auto ref = getRef();
		ref.get() = 255 + ref.get();
		std::cout << "func1 and func2 have the same loader so Reference<int> points the same int" << std::endl;
		std::cout << "func 2:) I hava a obj :) ref = " << ref.get() << std::endl;
		std::this_thread::sleep_for( std::chrono::seconds( 5 ) );
		return 0;
	}
	catch( DAL::ThisIsNotPossible* e ) {
		std::cout << "============================" << e->get() << std::endl << "============================" << std::endl;
		return -1;
	}
}


int main() {
	try {
		func1();
		func2();
		std::thread t1( func1 );
		std::thread t2( func2 );

		t1.join();
		t2.join();
		std::cout << "end" << std::endl;
	}
	catch( std::exception& e ) {
		std::cout << "============================" << e.what() << std::endl << "============================" << std::endl;
		return -1;
	}

	return 0;
}
