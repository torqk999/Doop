#pragma once
#include <DoopEssentials.h>
#include <SearchResult.h>

template<typename T>
class TSearchResult : SearchResult
{
public:
	TSearchResult(ResultCode code, T target = default);
	T Value();

private:
	T _target;
};

