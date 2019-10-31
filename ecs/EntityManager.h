#pragma once
#include "Entity.h"
#include "..//util/UniqueId.h"

class EntityManager
{

public:
	UniqueId CreateEntity();
	Entity* GetEntityById(UniqueId id);
	UniqueId GetEntityId();
};

