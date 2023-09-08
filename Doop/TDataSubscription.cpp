#include <TDataSubscription.h>

template<typename T>
TDataSubscription<T>::TDataSubscription(DataSystem* provider, int initialIndex)
{
	_elementIndex = initialIndex;
	_provider = provider;
}

template<typename T>
std::string* TDataSubscription<T>::GetType() { return typeid(T).name(); }

template<typename T>
T TDataSubscription<T>::GetValue(PropertyKey key) { return ((TDataSystem<T>*)_provider)->GetValue(_elementIndex, key); }
