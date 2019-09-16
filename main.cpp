
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Shader.h"
#include "ResourceManager.h"
#include "Renderer.h"


using namespace std;

int main() {

	ResourceManager* resManager = new ResourceManager();

	Window* window = new Window(800, 600, "Title");

	Renderer* renderer = new Renderer();

	Shader* shader = resManager->LoadShader("res/shaders/base_vector_shader.vs", "res/shaders/base_fragment_shader.fs");

#ifdef _DEBUG
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif
	

	while (!window->windowShouldClose) {
		window->Update();
		shader->Bind();

		GLfloat timeValue = glfwGetTime();
		GLfloat value = (sin(timeValue) / 2) + 0.5f;
		shader->SetUniform4f("timeColor", value, 1.0f, 0.5f, 1.0f);

		renderer->drawObject();
		window->SwapBuffers();
	}

	window->Shutdown();

	return EXIT_SUCCESS;
}
