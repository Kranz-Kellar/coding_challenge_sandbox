#pragma once
#include <GL/glew.h>
#include "renderer/IRenderer.h"
#include "SandBox/Chunk.h"


class ChunkRenderer
{
	IRenderer* baseRenderer;
	void Init();
public:
	


	ChunkRenderer(IRenderer* renderer);
	~ChunkRenderer();

	
	void DrawChunk(Chunk* chunk);
	
};

