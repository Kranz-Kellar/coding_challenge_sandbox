#pragma once

#include "Block.h"
#include <vector>

#define MAX_CHUNK_SIZE 10

class Chunk
{
public:
	std::vector<Block*> blocks;


	Chunk(std::vector<Block*> blocks) {
		this->blocks = blocks;
	};

	~Chunk() {
	};
};

