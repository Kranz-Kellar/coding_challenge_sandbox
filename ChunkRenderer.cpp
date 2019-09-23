#include "ChunkRenderer.h"

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
	//���������� ���� ����, ��������� �� ������
	//���� ���������� �� ����� � ��� �������������� � �������
	//���������� �������� ��������� �� ��������� ��� ����������

	//TODO: ��������� ����� ���� �������� ���� ���������� �� ���� ���, � �� �������� �� ������ ����

	for (unsigned int i = 0; i < MAX_CHUNK_SIZE; i++) {
		Block* block = chunk->blocks[i];
		block->sprite->texture->Bind();
	    baseRenderer->drawObject(block->sprite->shader, block->transform->GetModelMatrix());
	}
}
