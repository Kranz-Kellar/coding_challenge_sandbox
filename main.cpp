
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

using namespace std;


int main() {
	glm::vec3 viewPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 viewTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	Camera* camera = new Camera();
	Window* window = new Window(camera, 800, 600, "Title");

	window->subscribeOnEventType(EV_KEYBOARD);
	window->subscribeOnEventType(EV_MOUSE);
	window->SetCursor(false);

	InputManager* inputManager = new InputManager();
	inputManager->subscribeOnEventType(EV_KEYBOARD);
	inputManager->subscribeOnEventType(EV_MOUSE);
	inputManager->subscribeOnEventType(EV_NONE);

	EventManager::AddSystem(inputManager);
	EventManager::AddSystem(window);

	glfwSetWindowUserPointer(window->GetWindowPointer(), inputManager);


	ResourceManager* resManager = new ResourceManager();

	
	Renderer* renderer = new Renderer();

	Shader* shader = resManager->LoadShader("res/shaders/base_vector_shader.vs",
		"res/shaders/base_fragment_shader.fs");

	Texture2D* texture = resManager->LoadTexture("res/textures/test.png");

	
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)window->width / (GLfloat)window->height, 0.1f, 100.0f);


#ifdef _DEBUG
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif

	glm::vec3 cubePosition(0.0f, 0.0f, 0.0f);

	while (!window->windowShouldClose) {
	
		EventManager::ProcessEvents();
		window->Update();

		shader->Bind();
		shader->SetMat4f("view", window->camera->GetViewMatrix());
		shader->SetMat4f("projection", projection);


		glm::mat4 model(1.0f);
		model = glm::translate(model, cubePosition);
		model = glm::rotate(model, (GLfloat)sin(glfwGetTime()), glm::vec3(0.1f, 0.3f, 1.0f));
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		shader->SetMat4f("model", model);
		renderer->drawObject();

		window->SwapBuffers();

		//Получаем эвенты
	}

	window->Shutdown();
	resManager->ReleaseResources();

	delete resManager;
	delete window;
	delete renderer;
	delete camera;

	return EXIT_SUCCESS;
}
