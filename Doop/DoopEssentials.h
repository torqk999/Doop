#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>

#include <KeyDefinitions.h>

#define TRY try //__try { try
#define CATCH catch (const std::exception& e) //{} } __finally // Generic "lazy boi" catch


//void foo()
//{
//	__try { try
//	{ /*my code*/ }
//	catch (const std::exception& e) {} } __finally
//	{ /*my code*/ }
//}

#define STR_BUILD(oss) std::stringstream oss; oss << 
#define PRINT_F(oss) printf(oss.str().c_str());

class DoopGlobals
{
public:
	const static int DEFAULT_MEMBER_CAPACITY = 20;
	const static int MAX_ELEMENT_COUNT = 500;
	const static int MAX_ELEMENT_BYTE_SIZE = 16;
	static char* ZeroSample;
};