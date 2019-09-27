#pragma once
#include "Chunk.h"
#include "BlockManager.h"
typedef std::vector<std::vector<Block*>> _Chunk;
typedef std::vector<std::vector<Block*>>(*algorithmFunc)(void);


//TODO: Придумать оптимальный способ хранения дохреналиона блоков
//Либо представлять каждый блок, как BlockType и рендерить с помощью паттерна Prototype,
//клонируя один и тот же блок
class ChunkManager
{
	_Chunk GenerateBaseChunk() {
		//Инициализируем вектор, так как нам заранее известны размеры чанка
		_Chunk chunk (MAX_CHUNK_SIZE, std::vector<Block*>(MAX_CHUNK_SIZE));
		for (uint32_t x = 0; x < MAX_CHUNK_SIZE; x++) {
			for (uint32_t y = 0; y < MAX_CHUNK_SIZE; y++) {
				if (x > 32) {
					//Клонирование объекта, а не создание нового
					chunk[x][y] = BlockManager::CloneBlockOfType(B_DIRT);
					
				}
				else { 
					chunk[x][y] = BlockManager::CloneBlockOfType(B_EMPTY); 
				}
			}
		}

		return chunk;
	}
public:
	std::vector<Chunk*> chunks;


	void GenerateChunksFromMap(BlockType map[MAX_MAP_WIDTH][MAX_MAP_HEIGHT]) {
		for (uint32_t x = 0; x < MAX_MAP_WIDTH; x++) {
			for (uint32_t y = 0; y < MAX_MAP_HEIGHT; y++) {
				
			}
		}
	}

	_Chunk GenerateChunk(algorithmFunc chunkGenerationAlgorithm = nullptr) {
		if (chunkGenerationAlgorithm != nullptr) {
			_Chunk chunk = chunkGenerationAlgorithm();
			return chunk;
		}
		_Chunk chunk = GenerateBaseChunk();

		for (uint32_t x = 0; x < MAX_CHUNK_SIZE; x++) {
			for (uint32_t y = 0; y < MAX_CHUNK_SIZE ; y++) {
				std::cout << chunk[x][y];
			}
			std::cout << std::endl;
		}
		return chunk;
	}
};

