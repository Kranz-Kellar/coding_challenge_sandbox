#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Logger.h"
#include "Camera.h"
#include "System.h"
#include "events/KeyboardEvent.h"
#include "events/MouseEvent.h"

namespace Erbium {

	struct WindowAttributes {
		const char* title;
		GLuint width;
		GLuint height;
	};

	class Window : public Module
	{

		GLFWwindow* windowPtr;
		GLFWcursor* cursorPtr;
		const char* title;
		WindowAttributes attributes;
		Camera* camera;


		void Init();
		void SubscribeOnEvents();
		void InitGLFW();
		void CreateWindow();
		void LoadGLEW();
		void SetGenericGLFWCallbackForInputManager();
		void CreateAndSetStandartCursor();
		void Shutdown();
	public:

		Window(Camera* camera, int width, int height, const char* title);
		~Window();

		void Destroy();
		void Update();
		void SwapBuffers();
		void SetCursorDisplay(bool value);

		bool windowShouldClose;

		GLFWwindow* GetWindowPointer() {
			return this->windowPtr;
		}

		void processEvent(Event* event);

		void processKeyboardEvent(KeyboardEvent* event);

		void processMouseEvent(MouseEvent* event);


	};

}