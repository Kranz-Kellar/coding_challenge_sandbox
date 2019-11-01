#include "EntityManager.h"

EntityManager::EntityManager() : alloc(sizeof(Entity) * MAX_COUNT_OF_ENTITIES) {
	
}

UniqueId EntityManager::CreateEntity()
{
	return UniqueId();
}

Entity* EntityManager::GetEntityById(UniqueId id)
{
	return nullptr;
}

UniqueId EntityManager::GetEntityId()
{
	return UniqueId();
}

std::size_t EntityManager::GetAmountOfFreeMemory()
{
	return alloc.getAmountOfFreeMemory();
}

std::size_t EntityManager::GetAmountOfUsedMemory()
{
	return alloc.getAmountOfUsedMemory();
}

std::size_t EntityManager::GetAmountOfAllocatedMemory()
{
	return alloc.getAmountOfMaxMemory();
}
