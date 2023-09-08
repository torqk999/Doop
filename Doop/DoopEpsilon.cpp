#include "DoopEpsilon.h"

DoopEpsilon::DoopEpsilon()
{
	_name = nullptr;
}

DoopEpsilon::DoopEpsilon(const DoopEpsilon& copy)
{
	_name = copy._name;
}

bool DoopEpsilon::Configure(DoopConfig* config)
{
	_name = config->ObjectName;
	return true;
}

void DoopEpsilon::MyDoopConfiguration(DoopConfig* configBuffer)
{
	configBuffer->ObjectName = _name;
}
