#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Box2D/Box2D.h>

struct Position {
	float x;
	float y;

	Position(float _x, float _y) {
		x = _x;
		y = _y;
	}
};

class Transform
{
	
	glm::mat4 model;
	//b2BodyDef body;
	//b2Body* groundBody;
public:

	Transform(b2World* world = nullptr) {
		model = glm::mat4(1.0f);

	/*	if (world != nullptr) {
			body.type = b2_dynamicBody;
			body.position.Set(0.0f, 0.0f);
			body.angle = 0;

			groundBody = world->CreateBody(&body);
		}*/
	}

	void Translate(float x, float y) {
		model = glm::translate(model, glm::vec3(x, y, 0.0f));
		//body.position.Set(x, y);
	}

	void Scale(float x, float y) {
		model = glm::scale(model, glm::vec3(x, y, 0.0f));
	}

	void Rotate(float x, float y, float angle) {
		model = glm::rotate(model, angle, glm::vec3(x, y, 0.0f));
	}

	glm::mat4 GetModelMatrix() {
		return model;
	}

	//Position GetPosition() {
		//Position pos(body.position.x, body.position.y);

		//return pos;
	//}
};

