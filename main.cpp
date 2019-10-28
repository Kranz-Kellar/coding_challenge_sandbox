
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
#include <ctime>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Box2D/Box2D.h>


#include "EngineSystems.h"


#include "SandBox/Chunk.h"
#include "SandBox/MapGenerator.h"
#include "ChunkRenderer.h"

#include "Logger.h"

#include "mem/Allocator.h"

using namespace std;


int main() {


	EngineSystems engine;
	engine.InitSystems();

	//b2World* world = new b2World(b2Vec2(0.0f, -10.0f));

	srand(static_cast<unsigned>(time(0)));


	ChunkRenderer* chunkRenderer = new ChunkRenderer(static_cast<Renderer*>(engine.GetSystem("renderer")));

	std::shared_ptr<Shader> shader = static_cast<ResourceManager*>(engine.GetSystem("resourceManager"))->
		LoadShaderWithName("BaseShader",
			"res/shaders/base_vector_shader.vs",
		"res/shaders/base_fragment_shader.fs");

	std::shared_ptr<Texture2D> texture = static_cast<ResourceManager*>(engine.GetSystem("resourceManager"))->
		LoadTextureWithName("BaseTexture",
			"res/textures/test.png");

	std::vector<Block*> testBlocks;
	std::shared_ptr<Sprite> sprite = static_cast<ResourceManager*>(engine.GetSystem("resourceManager"))->
		GenerateSpriteFromTextureWithShader("Sprite",
			"BaseTexture",
			"BaseShader");
	
	//BlockManager::Initialize();

	for (unsigned int i = 0; i < 64; i++) {
		Transform transform(nullptr);
		transform.Translate(static_cast<GLfloat>(i), static_cast<GLfloat>(i));
		testBlocks.push_back(new Block(B_DIRT, transform, sprite));

	}

	Chunk* testChunk = new Chunk(testBlocks);



	//ChunkManager manager;
	//_Chunk chunk = manager.GenerateChunk();

#ifdef _DEBUG
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif

	double lastTime = glfwGetTime();
	double currentTime = 0.0f;
	double elapsedTime;
	while (!static_cast<Window*>(engine.GetSystem("window"))->windowShouldClose) {

		currentTime = glfwGetTime();
		elapsedTime = currentTime - lastTime;

		EventManager::ProcessEvents();
		static_cast<Window*>(engine.GetSystem("window"))->Update();

		chunkRenderer->DrawChunk(testChunk);

		static_cast<Window*>(engine.GetSystem("window"))->SwapBuffers();

		lastTime = currentTime;
	}


	delete chunkRenderer;

	engine.TerminateSystems();

	return EXIT_SUCCESS;
}
