#pragma once

#include <DoopEssentials.h>
#include <DoopEpsilon.h>

#include <DataSystem.h>

#include <SearchResult.h>


class DataOrientedObject : public DoopEpsilon
{
public:

	// Main function for adding "members" to your object.
	// Can be used at run-time, fails if the DataSystem is at full capacity
	bool SubscribeToSystem(DataSystem* system);

	// Always returns atleast 'default' initializer of type
	template<typename T>
	T GetValue(PropertyKey propKey, SystemKey sysKey);

	// Check to see if property exists;
	void GetResult(SearchResult* result, SearchConfig* configuration);

private:

	// subscriptions broken up by type, then by individual systems
	std::unordered_map<size_t, std::unordered_map<SystemKey, DataSubscription>> _subscriptions;
};