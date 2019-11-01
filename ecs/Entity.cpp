#include "Entity.h"

Entity::Entity() : id()
{
#ifdef _DEBUG
	Logger::Log("Entity was created", LOG_DEBUG);
#endif
}

Entity::~Entity() {
#ifdef _DEBUG
	Logger::Log("Entity was destroyed", LOG_DEBUG);
#endif
}
