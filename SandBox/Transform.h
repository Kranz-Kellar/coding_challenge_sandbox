#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Transform
{

	glm::mat4 model;

public:
	Transform(glm::mat4 matrix) {
		model = matrix;
	}

	void Translate(glm::vec3 vec) {
		model = glm::translate(model, vec);
	}

	void Scale(glm::vec3 vec) {
		model = glm::scale(model, vec);
	}

	void Rotate(glm::vec3 vec, float angle) {
		model = glm::rotate(model, angle, vec);
	}

	glm::mat4 GetModelMatrix() {
		return model;
	}

};

