#pragma once
#include <GL/glew.h>
#include "Renderer.h"
#include "SandBox/Chunk.h"


class ChunkRenderer
{
	Renderer* baseRenderer;
	void Init();
public:
	


	ChunkRenderer(Renderer* renderer);
	~ChunkRenderer();

	
	void DrawChunk(Chunk* chunk);
	
};

