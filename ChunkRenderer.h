#pragma once
#include <GL/glew.h>
#include "renderer/IRenderer.h"
#include "SandBox/Chunk.h"
#include "renderer/OpenGLDrawData.h"

namespace Erbium {

	class ChunkRenderer
	{
		IRenderer* baseRenderer;
		void Init();
	public:



		ChunkRenderer(IRenderer* renderer);
		~ChunkRenderer();


		void DrawChunk(Chunk* chunk);

	};
}

