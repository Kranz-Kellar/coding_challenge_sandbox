
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
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

using namespace std;


int main() {

#ifdef _DEBUG
	Logger::Log("DEBUG_MOD_ACTIVE", LOG_INFO);
#endif

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

	Shader* shader = resManager->LoadShader("C:/Users/Дмитрий/Desktop/Workplace/coding_challenge_sandbox/Debug/res/shaders/base_vector_shader.vs",
		"C:/Users/Дмитрий/Desktop/Workplace/coding_challenge_sandbox/Debug/res/shaders/base_fragment_shader.fs");

	Texture2D* texture = resManager->LoadTexture("C:/Users/Дмитрий/Desktop/Workplace/coding_challenge_sandbox/Debug/res/textures/test.png");



	Block* testBlocks[64];
	Sprite* sprite = new Sprite(shader, texture);

	for (unsigned int i = 0; i < 64; i++) {
		Transform* transform = new Transform(glm::mat4(1.0f));
		transform->Translate(glm::vec3(static_cast<GLfloat>(i), 0.0f, 0.0f));
		testBlocks[i] = new Block(B_DIRT, transform, sprite);
	}
	Chunk* testChunk = new Chunk(testBlocks, 64);



#ifdef _DEBUG
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif

	glm::vec3 cubePosition(0.0f, 0.0f, 0.0f);

	while (!window->windowShouldClose) {
	
		EventManager::ProcessEvents();
		window->Update();


		//glm::mat4 model(1.0f);
		//model = glm::translate(model, glm::vec3(0.0f, (GLfloat)sin(glfwGetTime()), 0.0f));
		//model = glm::rotate(model, (GLfloat)sin(glfwGetTime()), glm::vec3(0.0f, 0.0f, 0.0f));
		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.0f));
		//renderer->drawObject(shader, model);

		chunkRenderer->DrawChunk(testChunk);

		window->SwapBuffers();
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
