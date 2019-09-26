
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
#include <ctime>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"
#include "Shader.h"
#include "Texture2D.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Camera.h"
#include "InputManager.h"
#include "EventManager.h"


#include "SandBox/Chunk.h"
#include "ChunkRenderer.h"

#include "Logger.h"

#include "mem/Allocator.h"

using namespace std;


int main() {

#ifdef _DEBUG
	Logger::Log("DEBUG_MOD_ACTIVE", LOG_INFO);
#endif

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



	Block* testBlocks[64];
	std::shared_ptr<Sprite> sprite = resManager->GenerateSpriteFromTextureWithShader("Sprite", "BaseTexture", "BaseShader");
	

	for (unsigned int i = 0; i < 64; i++) {
		std::shared_ptr<Transform> transform = std::make_shared<Transform>(glm::mat4(1.0f));
		transform->Translate(glm::vec3(static_cast<GLfloat>(rand()) / (static_cast<GLfloat>(RAND_MAX/10.0f)),
			static_cast<GLfloat>(rand()) / (static_cast<GLfloat>(RAND_MAX / 10.0f)), 0.0f));
		//transform->Scale(glm::vec3(0.3f, 0.3f, 0.0f));
		testBlocks[i] = new Block(B_DIRT, transform, sprite);
	}

	Chunk* testChunk = new Chunk(testBlocks);


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
	/*delete testBlocks;*/
	delete chunkRenderer;

	return EXIT_SUCCESS;
}
