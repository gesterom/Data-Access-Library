#pragma once

#include <mutex>
#include <unordered_map>
#include <string>
#include <stdint.h>
#include <cstring>
#include <functional>
#include <exception>

#include <iostream>

namespace DAL{
	//def
	#include "Exeptions.h"
	#include "Object.h"
	#include "ILoader.h"
	#include "Manager.h"
	#include "Reference.h"
	#include "Factory.h"

	//imp
	#include "Object.imp"
	#include "Reference.imp"
	#include "Manager.imp"
};
