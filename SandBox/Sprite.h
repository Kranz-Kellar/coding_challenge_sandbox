#pragma once

#include "..//Shader.h"
#include "..//Texture2D.h"

class Sprite
{
public:
	Shader* shader;
	Texture2D* texture;

	Sprite(Shader* shader, Texture2D* texture) {
		this->shader = shader;
		this->texture = texture;
	}

};

