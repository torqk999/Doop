#include "TransformationSystem.h"


bool TransformationSystem::Setup(DataConfig* configBuffer)
{
	printf("Setting up Transformation System...\n");

	configBuffer->ObjectName = new std::string("Transformation System");
	configBuffer->ElementCapacity = DoopGlobals::DEFAULT_MEMBER_CAPACITY;
	configBuffer->PropertyCount = (int)TransformKey::TRANSFORM_KEYS_END;

	TransformKey* keyPtr = nullptr;
	float* typePtr = nullptr;

	ListGen(keyPtr, configBuffer);

	return Configure<float>(typePtr, configBuffer);
}
