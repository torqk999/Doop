#include "SearchResult.h"

SearchResult::SearchResult(SearchConfig* configuration)
{
	Configure(configuration);
}

void SearchResult::Configure(SearchConfig* configBuffer)
{
	DoopEpsilon::Configure(configBuffer);

	_target = configBuffer->ReturnLocation;

	_result = configBuffer->Result;
	_result = _result == ResultCode::Found_Valid && _target == nullptr ? ResultCode::Found_Null : _result;
	_result = _result == ResultCode::Found_Null && _target != nullptr ? ResultCode::Found_Valid : _result;
}

template<typename T>
T SearchResult::GetValue()
{
	try { return *((T*)&_target); }
	catch (const std::exception& e) { return T.default; }
}