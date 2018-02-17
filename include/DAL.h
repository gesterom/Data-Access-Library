#pragma once

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
	#include "ILoader.h"
	#include "Hash.h"
	#include "Manager.h"
	#include "Reference.h"
	#include "Factory.h"

	//imp
	template<typename Type>
	bool operator==(const ILoader<Type> & left, const ILoader<Type> & right){
		return hardByteEqual((char*)&left,(char*)&right,sizeof(left));
	}
	#include "ByteOperations.h"
	#include "Object.imp"
	#include "Hash.imp"
	#include "Reference.imp"
	#include "Manager.imp"
};
