#include <DataConfig.h>

DataConfig::DataConfig()
{
	ConfigBuffer = nullptr;
	SubscriptionBuffer = nullptr;
	TypeInfo = nullptr;
	KeyList = nullptr;

	PropertyKey = PropertyKey::NullProperty;

	PropertyCount = 0;
	ElementIndex = -1;
	ElementCount = 0;
	ElementCapacity = 0;
	ElementByteSize = 0;
}

DataConfig::~DataConfig()
{
	if (KeyList != NULL)
		delete KeyList;
}
