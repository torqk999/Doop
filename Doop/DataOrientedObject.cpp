#include "DataOrientedObject.h"

template<typename T>
T DataOrientedObject::GetValue(PropertyKey propKey, SystemKey sysKey)
{
	TRY{ return &_subscriptions[typeid(T).hash_code()][sysKey]; }
	CATCH{ T t; return t; }
}

void DataOrientedObject::GetResult(SearchResult* result, SearchConfig* configuration)
{
	// Type check
	std::unordered_map<SystemKey, DataSubscription> typeMap;
	TRY { typeMap = _subscriptions[configuration->DataType]; }
	CATCH
	{
		configuration->Result = ResultCode::Missing_ValueType;
		goto Result;
	}

	// Subscription check
	DataSubscription* targetSubscription;
	TRY{ targetSubscription = &typeMap[configuration->TargetSystem]; }
	CATCH
	{
		configuration->Result = ResultCode::Missing_Subscription;
		goto Result;
	}

	// Property check
	TRY
	{
		targetSubscription->GetValue(configuration);
		configuration->Result = ResultCode::Found_Valid;
	}
	CATCH
	{
		configuration->Result = ResultCode::Missing_SystemProperty;
	}

	Result:
		result = new SearchResult(configuration);
}

bool DataOrientedObject::SubscribeToSystem(DataSystem* system)
{
	// finish this...

	return false;
}
