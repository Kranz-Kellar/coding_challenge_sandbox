#pragma once
#include "Transform.h"
#include "Sprite.h"

using namespace Erbium;

enum BlockType {
	B_EMPTY,
	B_DIRT
};

class Block
{
public:
	BlockType type;
	Transform transform;
	std::shared_ptr<Sprite> sprite;

	Block(BlockType type) {
		this->type = type;
	};

	Block(BlockType type, Transform &transform) {
		this->type = type;
		this->transform = transform;
	};

	Block(BlockType type, Transform& transform, std::shared_ptr<Sprite> sprite) {
		this->type = type;
		this->transform = transform;
		this->sprite = sprite;
	};


	void SetTransfrom(Transform transfrom) {
		this->transform = transform;
	}

	void SetTransformByMapPosition(uint32_t x, uint32_t y) {

	}

	void SetSprite(std::shared_ptr<Sprite> sprite) {
		this->sprite = sprite;
	}
};

