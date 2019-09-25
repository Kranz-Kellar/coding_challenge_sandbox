#include "Renderer.h"

#define RIGHT_BOTTOM -0.5f, 0.5f, 0.0f
#define LEFT_BOTTOM -0.5f,-0.5f, 0.0f
#define RIGHT_TOP 0.5f, 0.5f, 0.0f
#define LEFT_TOP  0.5f,-0.5f, 0.0f

void Renderer::Init()
{
	/*
		Just for test
	*/
	GLfloat vertices[] = {
     
	
	RIGHT_TOP,  1.0f, 1.0f,

	 
	LEFT_TOP,  1.0f, 0.0f,

	 
	LEFT_BOTTOM,  0.0f, 0.0f,

	
	RIGHT_BOTTOM,  0.0f, 1.0f

	};

	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	//const float aspect = window->width / window->height;
	projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
}

Renderer::Renderer(Camera* camera)
{
	this->camera = camera;
	Init();
}

void Renderer::drawObject(std::shared_ptr<Shader> shader, glm::mat4 model /* Texture goes here */)
{
	shader->Bind();
	shader->SetMat4f("view", camera->GetViewMatrix());
	shader->SetMat4f("projection", this->projection);
	shader->SetMat4f("model", model);
	glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

}
