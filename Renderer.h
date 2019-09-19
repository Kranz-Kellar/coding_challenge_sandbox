#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include "Texture2D.h"

class Renderer
{

	GLuint VAO, VBO, IBO;

	void Init();
public:
	Renderer();

	void drawObject(Shader* shader, glm::mat4 model, glm::mat4 view, glm::mat4 projection);

};

