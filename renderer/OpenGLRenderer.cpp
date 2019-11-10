#include "OpenGLRenderer.h"


OpenGLRenderer::OpenGLRenderer()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	//const float aspect = window->width / window->height;
	projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	InitBufferOfType(this->StaticDrawVAO, GL_STATIC_DRAW);
	InitBufferOfType(this->DynamicDrawVAO, GL_DYNAMIC_DRAW);
	InitBufferOfType(this->StreamDrawVAO, GL_STREAM_DRAW);
}


void OpenGLRenderer::InitBufferOfType(GLuint buffer, GLuint type)
{
	GLuint boxVertices[] = {
	RIGHT_TOP,  1.0f, 1.0f,
	LEFT_TOP,  1.0f, 0.0f,
	LEFT_BOTTOM,  0.0f, 0.0f,
	RIGHT_BOTTOM,  0.0f, 1.0f
	};

	GLuint boxIndices[] = {
		0, 1, 3,
		1, 2, 3
	};

	glGenVertexArrays(1, &buffer);
	glBindVertexArray(buffer);

	GLuint VBO, IBO;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(boxVertices), boxVertices, type);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(boxIndices), boxIndices, type);

	glBindVertexArray(0);
}


void OpenGLRenderer::setCamera(Camera* camera)
{
	this->viewCamera = camera;
}

void OpenGLRenderer::Draw2DObject(IDrawData* drawData)
{
	if (viewCamera == nullptr) {
		Logger::Log("Camera is null!", LOG_ERROR);
		return;
	}

	OpenGLDrawData* openGLDrawData = dynamic_cast<OpenGLDrawData*>(drawData);
	openGLDrawData->shader->Bind();
	openGLDrawData->shader->SetMat4f("view", viewCamera->GetViewMatrix());
	openGLDrawData->shader->SetMat4f("projection", this->projection);
	openGLDrawData->shader->SetMat4f("model", openGLDrawData->modelMatrix);
	openGLDrawData->texture->Bind();
	SetBufferOfType(openGLDrawData->typeOfDraw);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}


void OpenGLRenderer::SetBufferOfType(GLuint type) const
{
	switch (type) {
	case GL_STATIC_DRAW:
		glBindVertexArray(this->StaticDrawVAO);
		break;
	case GL_DYNAMIC_DRAW:
		glBindVertexArray(this->DynamicDrawVAO);
		break;
	case GL_STREAM_DRAW:
		glBindVertexArray(this->StreamDrawVAO);
		break;
	}
}