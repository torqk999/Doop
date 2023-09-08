#pragma once
#include <DoopEssentials.h>
#include <DataSystem.h>
#include <TDataSubscription.h>

template<typename T>
class TDataSystem : DataSystem
{
public:
	TDataSystem(int elementCapacity, int propertyCount);
	~TDataSystem();

	DataSubscription* Subscribe() override;
	bool Resize(int elementCapacity, int propertyCount = -1) override;
	std::string GetType() override;

	T GetValue(int elementIndex, PropertyKey propertyKey);

protected:
	T* _data;
};

