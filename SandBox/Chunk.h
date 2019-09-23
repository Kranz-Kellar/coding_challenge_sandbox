#pragma once

#include "Block.h"

#define MAX_CHUNK_SIZE 64

class Chunk
{
public:
	Block* blocks[MAX_CHUNK_SIZE];


	Chunk(Block* generatedBlocks[], int size) {
		if (size > MAX_CHUNK_SIZE) {
			return;
		}

		for (unsigned int i = 0; i < MAX_CHUNK_SIZE; i++) {
			blocks[i] = generatedBlocks[i];
		}
	};

	~Chunk() {
	};
};

