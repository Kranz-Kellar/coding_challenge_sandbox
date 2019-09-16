#pragma once
#include <GL/glew.h>

class Texture2D
{
	GLuint id;
	GLuint width;
	GLuint height;
public:
	Texture2D(int width, int height, unsigned char* image);
	void Bind();
	void Unbind();
};

