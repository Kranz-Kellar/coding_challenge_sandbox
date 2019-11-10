#include "ChunkRenderer.h"
#include "Logger.h"

ChunkRenderer::ChunkRenderer(IRenderer* renderer)
{
	this->baseRenderer = renderer;
	Init();
}

ChunkRenderer::~ChunkRenderer()
{

}

void ChunkRenderer::Init()
{
	//baseRenderer = new Renderer();
}

void ChunkRenderer::DrawChunk(Chunk* chunk)
{


	//TODO: Render bunch of object in one draw call

	for (unsigned int i = 0; i < MAX_CHUNK_SIZE; i++) {
		Block* block = chunk->blocks[i];
		if (block == nullptr) {
			Logger::Log("Block was null", LOG_ERROR);
			continue;
		}

		if (block->sprite->texture == nullptr) {
			Logger::Log("Texture not found!", LOG_ERROR);
			continue;
		}

		if (block->sprite->shader == nullptr) {
			Logger::Log("Shader not found", LOG_ERROR);
			continue;
		}

	    baseRenderer->draw2DObject(block->sprite->shader, block->sprite->texture, block->transform.GetModelMatrix());
	}
}
