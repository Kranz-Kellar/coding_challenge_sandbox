
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


using namespace std;

int main() {

	ResourceManager* resManager = new ResourceManager();

	Window* window = new Window(800, 600, "Title");

	Renderer* renderer = new Renderer();

	Shader* shader = resManager->LoadShader("res/shaders/base_vector_shader.vs",
		"res/shaders/base_fragment_shader.fs");

	Texture2D* texture = resManager->LoadTexture("res/textures/test.png");

#ifdef _DEBUG
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif


	
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)window->width / (GLfloat)window->height, 0.1f, 100.0f);
	glm::mat4 view(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
	glm::vec3 viewPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 viewTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 viewDirection = glm::normalize(viewPos - viewDirection);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 viewRight = glm::normalize(glm::cross(up, viewDirection));
	glm::vec3 viewUp = glm::cross(viewDirection, viewRight);

	view = glm::lookAt(viewPos, viewTarget, up);

	glm::vec3 cubePositions[] = {
	glm::vec3(0.0f,  0.0f,  0.0f),
	glm::vec3(2.0f,  5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f,  3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f,  2.0f, -2.5f),
	glm::vec3(1.5f,  0.2f, -1.5f),
	glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	while (!window->windowShouldClose) {
		window->Update();

		shader->Bind();
		GLfloat radius = 1.0f;
		GLfloat camX = sin(glfwGetTime() * radius);
		GLfloat camZ = cos(glfwGetTime() * radius);
		view = glm::lookAt(glm::vec3(camX, 0, camZ), viewTarget, up);
		shader->SetMat4f("view", view);
		shader->SetMat4f("projection", projection);

		for (GLuint i = 0; i < 1; i++) {
			//texture->Bind();
			glm::mat4 model(1.0f);
			model = glm::translate(model, cubePositions[i]);
			model = glm::rotate(model, (GLfloat)sin(glfwGetTime()), glm::vec3(0.1f, 0.3f, 1.0f));
			model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
			shader->SetMat4f("model", model);
			renderer->drawObject();
		}

		window->SwapBuffers();
	}

	window->Shutdown();
	resManager->ReleaseResources();

	delete resManager;
	delete window;
	delete renderer;

	return EXIT_SUCCESS;
}
