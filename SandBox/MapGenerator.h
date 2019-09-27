#pragma once

#define MAX_MAP_HEIGHT 512
#define MAX_MAP_WIDTH 512

#include "ChunkManager.h"

class MapGenerator
{

	static void BasicMapFilling(BlockType map[MAX_MAP_WIDTH][MAX_MAP_HEIGHT]) {
		for (uint32_t x = 0; x < MAX_MAP_WIDTH; x++) {
			for (uint32_t y = 0; y < MAX_MAP_HEIGHT; y++) {
				
				if (x > MAX_MAP_WIDTH/2) {
					map[x][y] = B_DIRT;
				}
				else {
					map[x][y] = B_EMPTY;
				}
			}
		}
	}

public:

	//Основной метод, возращающий двумерный массив, заполненный типами блоков
	//TODO: Передача в качестве аргумента указатель на функцию,
	//которая будет генерировать карту по определённому алгоритму
	static void GenerateMap(void(*algrotihm(BlockType[MAX_MAP_WIDTH][MAX_MAP_HEIGHT])) = nullptr) 
	{
		auto map = new BlockType[MAX_MAP_WIDTH][MAX_MAP_HEIGHT];

		if (algrotihm != nullptr) {
			algrotihm(map);
			return;
		}

		BasicMapFilling(map);

		for (uint32_t x = 0; x < MAX_MAP_WIDTH; x++) {
			for (uint32_t y = 0; y < MAX_MAP_HEIGHT; y++) {
				std::cout << map[x][y];
			}
			std::cout << std::endl;
		}
	}

	
};

