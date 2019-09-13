
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Shader.h"

using namespace std;

int main() {

	Window* window = new Window(800, 600, "Title");
	

	GLfloat vertices[] = {
	 0.5f,  0.5f, 0.0f,  
	 0.5f, -0.5f, 0.0f,  
	-0.5f, -0.5f, 0.0f,  
	-0.5f,  0.5f, 0.0f   
	};
	GLuint indices[] = {  
		0, 1, 3,   
		1, 2, 3    
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	


	//======================================================
	const char* vs = "#version 330 core\n layout (location = 0) in vec3 position;\n void main() {\n gl_Position = vec4(position.x, position.y,	position.z, 1.0);\n }";



	const char* fs = "#version 330 core\n out vec4 color;\n void main() {\n color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n }\n";

	Shader* shader = new Shader(vs, fs);


	//===========================================================


	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	while (!window->windowShouldClose) {
		window->Update();
		shader->Bind();


		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);



		window->SwapBuffers();
	}

	window->Shutdown();
	return EXIT_SUCCESS;
}
