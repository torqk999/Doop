#pragma once
#include <DoopEssentials.h>

#include <DataComponent.h>
#include <DataSystem.h>

#include <SearchConfig.h>

class DataSubscription : public DataComponent
{
	friend class DataSystem;

public:
	DataSubscription();
	DataSubscription(DataSystem* provider, int initialIndex, DataConfig* configuration);
	DataSubscription(const DataSubscription& copy);
	bool GetValue(SearchConfig* configuration) override;

protected:
	int _elementIndex;
	DataSystem* _provider;
	
private:
	void ReIndex(int index);
};
