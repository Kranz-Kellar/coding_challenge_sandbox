
#pragma warning(disable : 4244)

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
#include <ctime>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Box2D/Box2D.h>

#include "Window.h"
#include "Shader.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Camera.h"
#include "InputManager.h"
#include "EventManager.h"


#include "SandBox/Chunk.h"
#include "SandBox/MapGenerator.h"
#include "ChunkRenderer.h"

#include "Logger.h"

#include "mem/Allocator.h"

using namespace std;


int main() {

#ifdef _DEBUG
	Logger::Log("DEBUG_MOD_ACTIVE", LOG_INFO);
#endif

	//b2World* world = new b2World(b2Vec2(0.0f, -10.0f));

	srand(static_cast<unsigned>(time(0)));

	Camera* camera = new Camera();
	Window* window = new Window(camera, 800, 600, "Boxel");

	window->subscribeOnEventType(EV_KEYBOARD);
    //window->subscribeOnEventType(EV_MOUSE);
	window->SetCursor(false);

	InputManager* inputManager = new InputManager();
	inputManager->subscribeOnEventType(EV_KEYBOARD);
	inputManager->subscribeOnEventType(EV_MOUSE);
	inputManager->subscribeOnEventType(EV_NONE);

	EventManager::AddSystem(inputManager);
	EventManager::AddSystem(window);

	glfwSetWindowUserPointer(window->GetWindowPointer(), inputManager);

	

	ResourceManager* resManager = new ResourceManager();

	
	Renderer* renderer = new Renderer(camera);

	ChunkRenderer* chunkRenderer = new ChunkRenderer(renderer);

	std::shared_ptr<Shader> shader = resManager->LoadShaderWithName("BaseShader","C:/Users/Дмитрий/Desktop/Workplace/coding_challenge_sandbox/Debug/res/shaders/base_vector_shader.vs",
		"C:/Users/Дмитрий/Desktop/Workplace/coding_challenge_sandbox/Debug/res/shaders/base_fragment_shader.fs");

	std::shared_ptr<Texture2D> texture = resManager->LoadTextureWithName("BaseTexture","C:/Users/Дмитрий/Desktop/Workplace/coding_challenge_sandbox/Debug/res/textures/test.png");



	std::vector<Block*> testBlocks;
	std::shared_ptr<Sprite> sprite = resManager->GenerateSpriteFromTextureWithShader("Sprite", "BaseTexture", "BaseShader");
	
	BlockManager::Initialize();

	for (unsigned int i = 0; i < 64; i++) {
		Transform transform(nullptr);
		transform.Translate(static_cast<GLfloat>(i), static_cast<GLfloat>(i));
		testBlocks.push_back(new Block(B_DIRT, transform, sprite));

	}

	Chunk* testChunk = new Chunk(testBlocks);



	ChunkManager manager;
	_Chunk chunk = manager.GenerateChunk();

#ifdef _DEBUG
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif
	double lastTime = glfwGetTime();
	double currentTime = 0.0f;
	double elapsedTime;
	while (!window->windowShouldClose) {
		currentTime = glfwGetTime();
		elapsedTime = currentTime - lastTime;
		

		//std::cout << elapsedTime << std::endl;

		EventManager::ProcessEvents();
		window->Update();

		chunkRenderer->DrawChunk(testChunk);

		window->SwapBuffers();

		lastTime = currentTime;
	}

	window->Shutdown();
	resManager->ReleaseResources();

	delete resManager;
	delete window;
	delete renderer;
	delete camera;
	delete chunkRenderer;


	
	


	return EXIT_SUCCESS;
}
