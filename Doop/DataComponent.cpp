#include "DataComponent.h"

DataComponent::DataComponent()
{
	_elementByteSize = 0;
	_configBuffer = nullptr;
	_type = nullptr;
}

DataComponent::DataComponent(const DataComponent& copy) : DoopEpsilon(copy)
{
	_elementByteSize = copy._elementByteSize;
	_configBuffer = copy._configBuffer;
	_type = copy._type;
}

bool DataComponent::_Configure(DataConfig* configuration)
{
	TRY
	{
		_elementByteSize = configuration->ElementByteSize;
		_configBuffer = configuration->ConfigBuffer;
		_type = configuration->TypeInfo;
	}
	CATCH{ return false; }
	return DoopEpsilon::Configure(configuration);
}

DataConfig* DataComponent::MyDataConfiguration()
{
	DoopEpsilon::MyDoopConfiguration(_configBuffer);
	_configBuffer->ElementByteSize = _elementByteSize;
	_configBuffer->ConfigBuffer = _configBuffer; // No idea how it was used last...
	return _configBuffer;
}

bool DataComponent::SetValue(SearchConfig* configBuffer)
{
	if (!GetValue(configBuffer))
		return false;

	char* writeLocation = configBuffer->ReturnLocation;
	char* readLocation = configBuffer->ValueLocation;

	for (int i = 0; i < _elementByteSize; i++)
	{
		*writeLocation = *readLocation;
		writeLocation ++;
		readLocation ++;
	}

	return true;
}
