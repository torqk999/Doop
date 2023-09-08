#pragma once
#include <DoopEssentials.h>
#include <TDataSystem.h>
#include <DataSubscription.h>

template<typename T>
class TDataSubscription : DataSubscription
{
public:
	TDataSubscription(DataSystem* provider, int initialIndex);

	std::string* GetType() override;

	T GetValue(PropertyKey key);

protected:
	DataSystem* _provider;
};
