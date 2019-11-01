#pragma once
#include "Entity.h"
#include "..//util/UniqueId.h"
#include "..//mem/Allocator.h"

#define MAX_COUNT_OF_ENTITIES 512

class EntityManager
{
	Allocator alloc;
public:
	

	EntityManager();
	UniqueId CreateEntity();
	Entity* GetEntityById(UniqueId id);
	UniqueId GetEntityId();

	std::size_t GetAmountOfFreeMemory();
	std::size_t GetAmountOfUsedMemory();
	std::size_t GetAmountOfAllocatedMemory();
};

