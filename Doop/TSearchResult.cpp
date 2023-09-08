#include "TSearchResult.h"

template<typename T>
TSearchResult<T>::TSearchResult(ResultCode code, T target)
{
	// Work on this logic later....
	_target = target;
	_result = code == ResultCode::Valid && target == NULL ? ResultCode::Null : code;
}

template<typename T>
T TSearchResult<T>::Value()
{
	try { return *_target; }
	catch (const std::exception& e) { T t; return t; }
}