#pragma once

#include <GL/glew.h>


class Renderer
{

	GLuint VAO, VBO, IBO;

	void Init();
public:
	Renderer();

	void drawObject();

};

