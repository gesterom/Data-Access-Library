#pragma once

#include <mutex>
#include <unordered_map>
#include <string>
#include <stdint.h>
#include <cstring>
#include <functional>
#include <exception>

#include <iostream>
#include <thread>

namespace DAL{
#define DBG(x) {std::cout<<std::this_thread::get_id()<<"\t["<<__FUNCTION__<<" , "<<__LINE__<<" ] \t \""<<__FILE__<<"\"\t"<<#x<<std::endl;}x;
#define DB(x) {std::cout<<std::this_thread::get_id()<<"\t["<<__FUNCTION__<<" , "<<__LINE__<<" ] \t"<<#x<<std::endl;}
#define DBG_VAR(x) {std::cout<<#x<<"\t A[ "<<x<<" ]"<<std::endl;}
	//def
	#include "Exception.h"
	#include "Object.h"
	#include "ILoader.h"
	#include "IUpdater.h"
	#include "Manager.h"
	#include "Reference.h"
	#include "Domain.h"

	//imp
	#include "Object.cpp"
	#include "Reference.cpp"
	#include "Manager.cpp"
};
