#pragma once

#include <vector>

#include "Chunk.h"

class World
{

public:
	//��� �����, ��� ���� ������������� �� �� �����
	std::vector<Chunk*> chunks;

	World(std::vector<Chunk*> _chunks) {
		this->chunks = _chunks;
	}

	//�����, ��� ������������ �� ������ ������
	//�������������� ���������� ������ ������
	std::vector<Chunk*> chunksInUse;
};

