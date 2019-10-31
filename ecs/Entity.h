#pragma once

#include "..//util/UniqueId.h"
#include "Component.h"
#include <vector>
#include <bitset>

typedef std::vector<bool> ComponentsMask;
typedef std::vector<Component> Components;

class Entity
{
	UniqueId id;
	ComponentsMask componentsMask;
	Components components;

	void* operator new(std::size_t count) = delete;
	void* operator new[](std::size_t count) = delete;
};

