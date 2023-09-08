#include <DataSystem.h>

bool DataSystem::Subscribe(DataSubscription* subscriptionBuffer)
{
	// No room left for subscriptions
	if (_elementCount >= _elementCapacity)
	{
		MyDataConfiguration();
		_configBuffer->ElementCapacity *= 2;

		//DataConfig* systemConfig = MyDataConfiguration();
		//systemConfig->ElementCapacity *= 2; // Double capacity by default

		if (!Reformat(_configBuffer))
			return false;
	}
		
	_configBuffer->ObjectName = new std::string(GetName()->c_str());
	_configBuffer->ConfigBuffer = _subscriptionBuffer;
	_configBuffer->ElementIndex = _elementCount;

	subscriptionBuffer = new DataSubscription(this, _elementCount, _configBuffer);

	_elementCount++;
	return true;
}

DataConfig* DataSystem::MyDataConfiguration()
{
	DataComponent::MyDataConfiguration();

	//_configBuffer->Target = _data;
	//_configBuffer->KeyMap = &_propertyKeys;
	_configBuffer->ElementCapacity = _elementCapacity;
	_configBuffer->ElementCount = _elementCount;

	return _configBuffer;
}
void DataSystem::UnSubscribe(DataSubscription* subscription) { }

void DataSystem::KeyGen(DataConfig* configBuffer)
{
	_propertyKeys.clear();
	for (int i = 0; i < configBuffer->PropertyCount; i++)
		_propertyKeys.insert(std::pair<PropertyKey, int>(configBuffer->KeyList[i], i));
}

DataSystem::~DataSystem()
{
	if (_data != NULL)
		delete[] _data;
}

bool DataSystem::Reformat(DataConfig* config)
{
	if (config->KeyList == NULL)
		return false;

	size_t newElementByteSize = config->ElementByteSize;
	int newElementCapacity = config->ElementCapacity;
	int newPropertyCount = config->PropertyCount;

	// Clamp element capacity, Keep default element capacity on -1
	newElementCapacity =
		newElementCapacity == -1 ? _elementCapacity :
		newElementCapacity < 0 ? 0 :
		newElementCapacity > DoopGlobals::MAX_ELEMENT_COUNT ? DoopGlobals::MAX_ELEMENT_COUNT :
		newElementCapacity;

	// Size hasn't changed... (Type-punning of entire data-block allowed! :D)
	if (newElementByteSize == _elementByteSize &&
		newElementCapacity == _elementCapacity &&
		newPropertyCount == PropertyCount() )
		return false;

	// buffer old elements if any
	char* temp = _data;

	// Re-size dataBlock
	int newCapacity = newElementCapacity * newPropertyCount * (int)newElementByteSize;
	_data = new char[newCapacity];

	// transfer old elements and release un-used block
	if (temp != nullptr)
	{
		for (int i = 0; i < PropertyCount() && i < newPropertyCount; i++)
			for (int j = 0; j < _elementCapacity && j < newElementCapacity; j++)
				_data[(i * newElementCapacity) + j] = temp[(i * _elementCapacity) + j];
			
		delete[] temp;
	}

	KeyGen(config);
	_elementCapacity = newElementCapacity;
	return true;
}

bool DataSystem::GetValue(SearchConfig* config)
{
	TRY
	{
		size_t byteOffset =     // Vertical and horizontal offset
			(size_t)((PropertyIndex(config->TargetProperty) * _elementCapacity) + config->ElementIndex)
			* _elementByteSize; // Scale up total byte count

		// Must stay inside the allocation of _data!
		if (byteOffset < 0 || byteOffset >= DataByteSize())
			return false;

		// Cast the raw adress to the type pointer
		config->ReturnLocation = _data + byteOffset;
		return true;
	}

	CATCH { return false; }
}

DataSystem::DataSystem()
{
	_elementCapacity = 0;
	_elementByteSize = 0;
	_elementCount = 0;

	_subscriptionBuffer = nullptr;
	_data = nullptr;
}

bool DataSystem::_Configure(DataConfig* config)
{
	TRY
	{
		_subscriptionBuffer = config->SubscriptionBuffer;
		Reformat(config);
	}

	CATCH{ return false; }
	
	return DataComponent::_Configure(config);
}

int DataSystem::PropertyIndex(PropertyKey key)
{
	TRY { return _propertyKeys[key]; }
	CATCH { return -1; }
}


