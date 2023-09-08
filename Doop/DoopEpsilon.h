#pragma once
#include <DoopEssentials.h>
#include <DataConfig.h>

class DoopEpsilon
{
public:
	DoopEpsilon();
	DoopEpsilon(const DoopEpsilon& copy);
	
	std::string* GetName() { return _name; }

protected:
	bool Configure(DoopConfig* configBuffer);
	void MyDoopConfiguration(DoopConfig* configBuffer);
	
	std::string* _name;
};

