#pragma once

#include <map>
#include "Block.h"

class BlockManager
{
	static void AddBlockOfType(BlockType type) {

	}

public:

	//Содержит по одному блоку одного типа
	//С помощью этого map'а копируются остальные блоки
	static std::map<BlockType, Block*> blocksMap;

	static void Initialize() {
		
	}

	static Block* CloneBlockOfType(BlockType type) {
		Block* block = new Block(type);
		block->SetSprite(blocksMap[type]->sprite);

		return block;
	}



};

