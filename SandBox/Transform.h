#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


struct Point {
	double x;
	double y;
};

class Transform
{
	
	glm::mat4 model;

public:
	Point position;
	Transform(glm::mat4 matrix) {
		model = matrix;
		position.x = 0;
		position.y = 0;
	}

	void Translate(glm::vec3 vec) {
		model = glm::translate(model, vec);
		position.x = vec.x;
		position.y = vec.y;
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

