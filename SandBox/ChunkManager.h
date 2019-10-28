#pragma once
#include "Chunk.h"
#include "BlockManager.h"
typedef std::vector<std::vector<Block*>> _Chunk;
typedef std::vector<std::vector<Block*>>(*algorithmFunc)(void);

#define MAX_MAP_WIDTH 512
#define MAX_MAP_HEIGHT 512

//TODO: ��������� ����������� ������ �������� ������������ ������
//���� ������������ ������ ����, ��� BlockType � ��������� � ������� �������� Prototype,
//�������� ���� � ��� �� ����
class ChunkManager
{
	_Chunk GenerateBaseChunk() {
		//�������������� ������, ��� ��� ��� ������� �������� ������� �����
		_Chunk chunk (MAX_CHUNK_SIZE, std::vector<Block*>(MAX_CHUNK_SIZE));
		for (uint32_t x = 0; x < MAX_CHUNK_SIZE; x++) {
			for (uint32_t y = 0; y < MAX_CHUNK_SIZE; y++) {
				if (x > MAX_CHUNK_SIZE / 2) {
					//������������ �������, � �� �������� ������
					//chunk[x][y] = BlockManager::CloneBlockOfType(B_DIRT);
				}
				else {
					//chunk[x][y] = BlockManager::CloneBlockOfType(B_EMPTY);
				}
			}
		}

		return chunk;
	}
public:
	std::vector<Chunk*> chunks;


	void GenerateChunksFromMap(BlockType map[MAX_MAP_WIDTH][MAX_MAP_HEIGHT]) {

#ifdef _DEBUG
		for (uint32_t x = 0; x < MAX_MAP_WIDTH; x++) {
			for (uint32_t y = 0; y < MAX_MAP_HEIGHT; y++) {
				
			}
		}
#endif

	}

	_Chunk GenerateChunk(/*algorithmFunc chunkGenerationAlgorithm = nullptr*/) {
		/*if (chunkGenerationAlgorithm != nullptr) {
			_Chunk chunk = chunkGenerationAlgorithm();
			return chunk;
		}*/
		_Chunk chunk = GenerateBaseChunk();

#ifdef _DEBUG
		for (uint32_t x = 0; x < MAX_CHUNK_SIZE; x++) {
			for (uint32_t y = 0; y < MAX_CHUNK_SIZE ; y++) {
				std::cout << chunk[x][y]->type;
			}
			std::cout << std::endl;
		}
#endif

		return chunk;
	}
};

