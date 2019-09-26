#pragma once
#include "Transform.h"
#include "Sprite.h"

#include <Box2D/Box2D.h>

enum BlockType {
	B_EMPTY,
	B_DIRT
};

class Block
{
public:

	b2BodyDef body;
	b2Body* groundBody;

	Block(BlockType type, std::shared_ptr<Transform> transform, std::shared_ptr<Sprite> sprite) {
		this->type = type;
		this->transform = transform;
		this->sprite = sprite;

		body.position.Set(0.0f, 0.0f);
		
	};

	BlockType type;
	std::shared_ptr<Transform> transform;
	std::shared_ptr<Sprite> sprite;

	
};



