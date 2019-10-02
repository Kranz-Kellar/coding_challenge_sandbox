#pragma once

#include <map>
#include "Block.h"

class BlockManager
{
	static void AddBlockOfType(BlockType type) {
		blocksMap[type] = new Block(type);
	}

public:

	//Содержит по одному блоку одного типа
	//С помощью этого map'а копируются остальные блоки
	static std::map<BlockType, Block*> blocksMap;

	static void Initialize() {
		BlockManager::AddBlockOfType(B_DIRT);
		BlockManager::AddBlockOfType(B_EMPTY);
	}

	static Block* CloneBlockOfType(BlockType type) {

		if (blocksMap[type] != nullptr) {
			Logger::Log("That type of block does't exist", LogStatus::LOG_ERROR);
			return nullptr;
		}

		Block* block = new Block(type);
		block->SetSprite(blocksMap[type]->sprite);

		return block;
	}



};

std::map<BlockType, Block*> BlockManager::blocksMap;