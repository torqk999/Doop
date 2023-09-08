#pragma once
#include <DoopEssentials.h>
#include <DoopConfig.h>

/// <summary>
/// When using a DataConfig, be mindful that the pointer which is consumed by
/// any constructor of the 'Data' class hierarchy, will both provide the initializers,
/// as well the working 'config buffer' for any future interactions.This is to reduce
/// on memory over-head, while being slightly more taxing in calls. Any use of the buffer
/// should be consumed or copied immediately, is not risidual!
/// </summary>
struct DataConfig : DoopConfig
{
public:
	DataConfig();
	~DataConfig();

	static const DataConfig NullData;

	DataConfig* ConfigBuffer;
	DataConfig* SubscriptionBuffer;
	PropertyKey* KeyList;

	PropertyKey PropertyKey;
	type_info* TypeInfo;
	size_t ElementByteSize;

	int
		PropertyCount,
		ElementIndex,
		ElementCount,
		ElementCapacity;
};

