#pragma once

#include <DoopEssentials.h>
#include <DoopEpsilon.h>

#include <DataConfig.h>
#include <SearchConfig.h>

class DataComponent : public DoopEpsilon
{
public:
	DataComponent();
	DataComponent(DataConfig* configBuffer) { _Configure(configBuffer); }
	DataComponent(const DataComponent& copy);

	type_info* GetType() { return _type; }
	size_t ElementByteSize() { return _elementByteSize; }

	virtual DataConfig* MyDataConfiguration();
	virtual bool GetValue(SearchConfig* configBuffer) { return false; }
	bool SetValue(SearchConfig* configBuffer);

	template<typename T>
	void GetDefaultValue(T* targetBuffer) { targetBuffer = (T*)DoopGlobals::ZeroSample; }

protected:
	template<typename T>
	bool Configure(T* type, DataConfig* configBuffer)
	{
		bool configurationSuccess;

		TRY
		{
			configBuffer->TypeInfo = const_cast<type_info*>(&typeid(T));
			configBuffer->ElementByteSize = sizeof(T);
			configurationSuccess = _Configure(configBuffer);
		}
		CATCH{ configurationSuccess = false; }

		STR_BUILD(oss)"Configured: " << (configurationSuccess ? "True" : "False") << "\n";
		PRINT_F(oss)

		return configurationSuccess;
	};

	virtual bool _Configure(DataConfig* configBuffer);

	type_info* _type;
	size_t _elementByteSize;
	DataConfig* _configBuffer;
};
