#pragma once
#include <DoopEssentials.h>

#include <DataSystem.h>
/*
* 
*	R_X, R_Y, R_Z, R_S
*	U_X, U_Y, U_Z, U_S
*	F_X, F_Y, F_Z, F_S
*	P_X, P_Y, P_Z, P_S
* 
*/

class TransformationSystem : public DataSystem
{
public:
	const int TRANSFORM_PROPERTY_COUNT = 16;
	bool Setup(DataConfig* configBuffer);
};

