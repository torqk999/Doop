#pragma once
#include <DoopEssentials.h>

#include <DataComponent.h>
#include <DataSubscription.h>

#include <SearchConfig.h>

class DataSystem : public DataComponent
{
	friend class DataSubscription;

public:
	DataSystem();
	~DataSystem();
	template<typename T>
	DataSystem(DataConfig* configBuffer) { Configure<T>(configBuffer); }

	bool Reformat(DataConfig* configBuffer);
	bool Subscribe(DataSubscription* subscriptionBuffer);

	bool GetValue(SearchConfig* configBuffer) override;

	int PropertyCount() { return (int)_propertyKeys.size(); }
	int ElementCapacity() { return _elementCapacity; }
	int ElementCount() { return _elementCount; }

	size_t DataByteSize() { return _propertyKeys.size() * _elementByteSize * _elementCapacity; }
	size_t DataAddress() { return (size_t)_data; }

protected:
	virtual bool _Configure(DataConfig* configBuffer) override;
	virtual DataConfig* MyDataConfiguration() override;
	void UnSubscribe(DataSubscription* subscription);
	void KeyGen(DataConfig* configBuffer);

	template<typename E>
	void ListGen(E* enumPtr, DataConfig* configBuffer)
	{
		if (!std::is_enum_v<E>)
			return;

		if (configBuffer->KeyList != NULL)
			delete[] configBuffer->KeyList;

		configBuffer->KeyList = new PropertyKey[configBuffer->PropertyCount];
		for (int i = 0; i < configBuffer->PropertyCount; i++)
			configBuffer->KeyList[i] = (PropertyKey)i;

		printf("List Generated!\n");
	}

	int PropertyIndex(PropertyKey key);
	std::unordered_map<PropertyKey, int> _propertyKeys;
	int _elementCapacity;
	int _elementCount;

private:
	DataConfig* _subscriptionBuffer;
	char* _data;
};


