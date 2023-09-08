#include <DataSubscription.h>

DataSubscription::DataSubscription()
{
	_provider = nullptr;
	_elementIndex = -1;
}

DataSubscription::DataSubscription(DataSystem* provider, int initialIndex, DataConfig* configuration)
{
	_Configure(configuration);

	_provider = provider;
	ReIndex(initialIndex);
}

DataSubscription::DataSubscription(const DataSubscription& copy) : DataComponent(copy)
{
	_elementIndex = copy._elementIndex;
	_provider = copy._provider;
}

void DataSubscription::ReIndex(int index)
{
	_elementIndex = index;
}

bool DataSubscription::GetValue(SearchConfig* configuration)
{
	try { _provider->GetValue(configuration); return true; }
	CATCH{ configuration->ReturnLocation = const_cast<char*>(DoopGlobals::ZeroSample); return false; }
}