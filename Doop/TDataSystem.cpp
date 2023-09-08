#include "TDataSystem.h"

template<typename T>
TDataSystem<T>::TDataSystem(int elementCapacity, int propertyCount)
{
	_lastElement = -1;
	Resize(elementCapacity, propertyCount);
}

template<typename T>
DataSubscription* TDataSystem<T>::Subscribe()
{
	int newIndex = _lastElement + 1;

	// No room left for subscriptions
	if (newIndex >= _elementCapacity
		&& !Resize(2 * _elementCapacity))
		return nullptr;

	_lastElement = newIndex;

	return new TDataSubscription<T>(this, newIndex);
}

template<typename T>
bool TDataSystem<T>::Resize(int elementCapacity, int propertyCount)
{
	// Keep default property count on -1
	_propertyCount = propertyCount == -1 ? _propertyCount : propertyCount;

	// Clamp element capacity, Keep default element capacity on -1
	elementCapacity =
		elementCapacity == -1 ? _elementCapacity :
		elementCapacity < 0 ? 0 :
		elementCapacity > MAX_ELEMENTS ? MAX_ELEMENTS :
		elementCapacity;

	// Nothing changed...
	if (elementCapacity == _elementCapacity &&
		propertyCount == _propertyCount)
		return false;

	// buffer old elements if any, and re-allocate new block
	T* temp = _data;
	_data = new T[elementCapacity * propertyCount];

	if (temp != NULL)
		for (int i = 0; i < _propertyCount; i++)
			for (int j = 0; j < _elementCapacity && j < elementCapacity; j++)
				_data[(i * elementCapacity) + j] = temp[(i * _elementCapacity) + j];

	_elementCapacity = elementCapacity;
	return true;
}

template<typename T>
std::string TDataSystem<T>::GetType() { return typeid(T).name(); }

template<typename T>
T TDataSystem<T>::GetValue(int elementIndex, PropertyKey propertyKey)
{
	int propertyIndex = PropertyIndex(propertyKey);
	if (propertyIndex == -1)
		return new T();
	return &_data[(propertyIndex * _elementCapacity) + elementIndex];
}

template<typename T>
TDataSystem<T>::~TDataSystem()
{
	if (_data != NULL)
		delete _data;
}