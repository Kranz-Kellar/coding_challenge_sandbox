#pragma once
#include <GL/glew.h>


class ChunkRenderer
{
	GLuint VAO;
	GLuint VBO;
	GLuint IBO;
public:
	


	ChunkRenderer();

	void Init();
	void DrawChunk(/* Chunk goes here */);
	
};

