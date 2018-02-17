#include <mutex>
#include <unordered_map>
#include <string>
#include <stdint.h>
#include <cstring>
#include <functional>
#include <exception>

namespace DAL{
	//def
	#include "Exeptions.h"
	#include "ByteOperations.h"
	#include "Object.h"
	#include "Loader.h"
	#include "Hash.h"
	#include "Manager.h"
	#include "Reference.h"
	#include "Factory.h"

	//loader injection
	#ifndef SPECIALIZED_LOADERS_HEADER
	#error "SPECIALIZED_LOADERS_HEADER must contein path to your header with specialized loaders"
	#endif
	
	#ifdef SPECIALIZED_LOADERS_HEADER
	#include SPECIALIZED_LOADERS_HEADER
	#endif

	//imp
	template<typename Type>
		bool operator==(const Loader<Type> & left, const Loader<Type> & right){
		return hardByteEqual((char*)&left,(char*)&right,sizeof(Loader<Type>));
	}
	#include "ByteOperations.h"
	#include "Object.imp"
	#include "Hash.imp"
	#include "Reference.imp"
	#include "Manager.imp"
};
