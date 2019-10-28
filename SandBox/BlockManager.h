#pragma once

#include <map>
#include "Block.h"
#include "../Logger.h"


typedef std::map<BlockType, Block*> BlocksMap;

class BlockManager
{
	void AddBlockOfType(BlockType type) {
		blocksMap[type] = new Block(type);
	}

	//Содержит по одному блоку одного типа
	//С помощью этого map'а копируются остальные блоки
	 BlocksMap blocksMap;

public:

	

	void Initialize() {
		BlockManager::AddBlockOfType(B_DIRT);
		BlockManager::AddBlockOfType(B_EMPTY);
	}

	Block* CloneBlockOfType(BlockType type) {

		if (blocksMap[type] == nullptr) {
			Logger::Log("That type of block does't exist", LogStatus::LOG_ERROR);
			return nullptr;
		}

		Block* block = new Block(type);
		block->SetSprite(blocksMap[type]->sprite);

		return block;
	}
};

