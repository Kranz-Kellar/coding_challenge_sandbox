#pragma once
#pragma warning(push)
#pragma warning( disable : 4244 ) 

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "System.h"

namespace Erbium {

	enum CameraMovement {
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	const double YAW = -90.0f;
	const double PITCH = 0.0f;
	const double SPEED = 2.5f;
	const double SENSITIVITY = 0.1f;
	const double ZOOM = 45.0f;

	class Camera : public Module
	{

		void updateCameraVectors()
		{

			glm::vec3 front;
			front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			front.y = sin(glm::radians(Pitch));
			front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			Front = glm::normalize(front);

			Right = glm::normalize(glm::cross(Front, WorldUp));
			Up = glm::normalize(glm::cross(Right, Front));
		}

	public:
		// Camera Attributes
		glm::vec3 Position;
		glm::vec3 Front;
		glm::vec3 Up;
		glm::vec3 Right;
		glm::vec3 WorldUp;

		double Yaw;
		double Pitch;

		double MovementSpeed;
		double MouseSensitivity;
		double Zoom;

		double lastX;
		double lastY;

		//Добавить понятие цели
		//Камера постоянно будет следит за этой целью, обновляя свои координаты, когда цель будет передвигаться


		Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
			double yaw = YAW, double pitch = PITCH)
			: Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), lastY(300), lastX(400)
		{
			Position = position;
			WorldUp = up;
			Yaw = yaw;
			Pitch = pitch;
			updateCameraVectors();
		}

		Camera(glm::vec3 position)
			: Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), lastY(300), lastX(400)
		{
			Position = glm::vec3(0.0f, 0.0f, 0.0f);
			WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
			Yaw = YAW;
			Pitch = PITCH;
			updateCameraVectors();
		}


		glm::mat4 GetViewMatrix()
		{
			return glm::lookAt(Position, Position + Front, Up);
		}


		void ProcessKeyboard(CameraMovement direction, double deltaTime)
		{
			float velocity = MovementSpeed * deltaTime;
			if (direction == FORWARD)
				Position += Front * velocity;
			if (direction == BACKWARD)
				Position -= Front * velocity;
			if (direction == LEFT)
				Position -= Right * velocity;
			if (direction == RIGHT)
				Position += Right * velocity;
			if (direction == UP)
				Position += Up * velocity;
			if (direction == DOWN)
				Position -= Up * velocity;
		}


		void ProcessMouseMovement(double newX, double newY, GLboolean constrainPitch = true)
		{
			/*if (lastX == newX && lastY == newY)
				return;

			//Поменяй, если нужно будет реверснуть движение мыши
			double xoffset = newX - lastX;
			double yoffset = lastY - newY;

			lastX = newX;
			lastY = newY;

			xoffset *= MouseSensitivity;
			yoffset *= MouseSensitivity;

			Yaw += xoffset;
			Pitch += yoffset;


			if (constrainPitch)
			{
				if (Pitch > 89.0f)
					Pitch = 89.0f;
				if (Pitch < -89.0f)
					Pitch = -89.0f;
			}


			updateCameraVectors();*/
		}


		void ProcessMouseScroll(double yoffset)
		{
			if (Zoom >= 1.0f && Zoom <= 45.0f)
				Zoom -= yoffset;
			if (Zoom <= 1.0f)
				Zoom = 1.0f;
			if (Zoom >= 45.0f)
				Zoom = 45.0f;
		}
	};

}
#pragma warning(pop)