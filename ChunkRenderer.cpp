#include "ChunkRenderer.h"
#include "Logger.h"

ChunkRenderer::ChunkRenderer(Renderer* renderer)
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
	//Перебираем весь чанк, состоящий из блоков
	//Берём информацию из блока о его местоположении и шейдере
	//Отправляем базовому рендереру на отрисовку эту информацию

	//TODO: Отрисовка чанка путём загрузки всей информации за один раз, а не вызовами на каждый блок

	for (unsigned int i = 0; i < MAX_CHUNK_SIZE; i++) {
		Block* block = chunk->blocks[i];
		if (block == nullptr) {
			Logger::Log("Block was null", LOG_ERROR);
			continue;
		}

		block->sprite->texture->Bind();
	    baseRenderer->drawObject(block->sprite->shader, block->transform.GetModelMatrix());
	}
}
