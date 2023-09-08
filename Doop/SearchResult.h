#pragma once
#include <DoopEssentials.h>
#include <DoopEpsilon.h>

#include <SearchConfig.h>

struct SearchResult : DoopEpsilon
{
public:
	SearchResult(SearchConfig* configuration) ;
	ResultCode Result() { return _result; }

	template<typename T>
	T GetValue();

protected:
	void Configure(SearchConfig* configBuffer);
	ResultCode _result;
	void* _target;
};

