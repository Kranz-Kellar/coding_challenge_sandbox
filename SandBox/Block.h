#pragma once
#include "Transform.h"
#include "Sprite.h"

enum BlockType {
	B_EMPTY,
	B_DIRT
};

class Block
{
public:

	Block(BlockType type, std::shared_ptr<Transform> transform, std::shared_ptr<Sprite> sprite) {
		this->type = type;
		this->transform = transform;
		this->sprite = sprite;
	};

	BlockType type;
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Sprite> sprite;

	
};



