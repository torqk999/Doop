#pragma once

#include <DoopEssentials.h>
#include <DoopConfig.h>
#include <ResultCode.h>

struct SearchConfig : DoopConfig
{
public:
	size_t DataType;
	SystemKey TargetSystem;
	PropertyKey TargetProperty;
	ResultCode Result;
	int ElementIndex;

	char* ReturnLocation;
	char* ValueLocation;
};