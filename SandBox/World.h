#pragma once

#include <vector>

#include "Chunk.h"

class World
{

public:
	//Все чанки, что были сгенерированы за всё время
	std::vector<Chunk*> chunks;

	World(std::vector<Chunk*> _chunks) {
		this->chunks = _chunks;
	}

	//Чанки, что используются на данный момент
	//Ограничиваются дальностью обзора камеры
	std::vector<Chunk*> chunksInUse;
};

