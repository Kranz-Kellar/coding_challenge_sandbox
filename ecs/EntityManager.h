#pragma once
#include "Enity.h"
#include "..//util/UniqueId.h"

class EntityManager
{

public:
	UniqueId CreateEntity();
	Entity* GetEntityById(UniqueId id);
	UniqueId GetEntityId();
};

