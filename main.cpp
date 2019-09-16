
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
	
	glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans(1.0f);
	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	trans = glm::scale(trans, glm::vec3(0.5f, 0.5f, 0.5f));

	while (!window->windowShouldClose) {
		window->Update();

		shader->Bind();
		texture->Bind();
		shader->SetMat4f("transform", trans);
		renderer->drawObject();
		window->SwapBuffers();
	}

	window->Shutdown();
	resManager->ReleaseResources();

	delete resManager;
	delete window;
	delete renderer;

	return EXIT_SUCCESS;
}
