#pragma once

#include "..//Shader.h"
#include "..//Texture2D.h"

//Вся информация для рендерера
class Sprite
{
public:
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Texture2D> texture;

	Sprite(std::shared_ptr<Shader> shader, std::shared_ptr<Texture2D> texture) {
		this->shader = shader;
		this->texture = texture;
	}

	void* operator new(size_t size) = delete;

};

