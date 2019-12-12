#pragma once

#include "Block.h"
#include <vector>

#define MAX_CHUNK_SIZE 10

class Chunk
{
public:
	std::vector<std::shared_ptr<Block>> blocks;


	Chunk(std::vector<std::shared_ptr<Block>> blocks) {
		this->blocks = blocks;
	};

	~Chunk() {
	};
};

