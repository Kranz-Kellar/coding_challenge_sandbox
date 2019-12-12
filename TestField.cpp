#include "TestField.h"



TestField::TestField(EngineSystems* engine)
{
	this->engine = engine;
}

void TestField::Init()
{

	chunkRenderer = new ChunkRenderer(dynamic_cast<IRenderer*>(engine->GetSystem("renderer")));

	std::shared_ptr<Shader> shader = dynamic_cast<ResourceManager*>(engine->GetSystem("resourceManager"))->
		LoadShaderWithName("BaseShader",
			"res/shaders/base_vector_shader.vs",
			"res/shaders/base_fragment_shader.fs");


	std::shared_ptr<Texture2D> texture = dynamic_cast<ResourceManager*>(engine->GetSystem("resourceManager"))->
		LoadTextureWithName("BaseTexture",
			"res/textures/test.png");

	std::shared_ptr<Sprite> sprite = dynamic_cast<ResourceManager*>(engine->GetSystem("resourceManager"))->
		GenerateSpriteFromTextureWithShader("Sprite",
			"BaseTexture",
			"BaseShader");

   
	for (unsigned int i = 0; i < 1; i++) {
		Transform transform(nullptr);
		transform.Translate(static_cast<GLfloat>(i), static_cast<GLfloat>(i), -10.0f);
		testBlocks.push_back(std::make_shared<Block>(B_DIRT, transform, sprite));
	}

	testChunk = new Chunk(testBlocks);
}

void TestField::Run()
{
	chunkRenderer->DrawChunk(testChunk);
}

void TestField::Terminate()
{
	delete chunkRenderer;

}
