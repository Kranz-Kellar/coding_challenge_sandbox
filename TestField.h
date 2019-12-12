#pragma once
#include "EngineSystems.h"
#include "ChunkRenderer.h"

using namespace Erbium;

class TestField
{
private:
	
public:
	TestField(EngineSystems* engine);
	void Init();
	void Run();
	void Terminate();



	ChunkRenderer* chunkRenderer;
	EngineSystems* engine;
	Chunk* testChunk;
	std::vector<std::shared_ptr<Block>> testBlocks;
};

