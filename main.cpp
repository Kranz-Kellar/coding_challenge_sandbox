
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <iostream>
#include <ctime>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Box2D/Box2D.h>


#include "EngineSystems.h"

#include "Logger.h"

#include "mem/Allocator.h"

#include <imgui/imgui.h>
#include "gui/imgui/imgui_impl_glfw.h"
#include "gui/imgui/imgui_impl_opengl3.h"

#include "TestField.h"

#include "AsyncFileIO.h"

using namespace std;
using namespace Erbium;


int main() {
	EngineSystems engine;
	engine.InitSystems();

	TestField* testField = new TestField(&engine);
	testField->Init();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplGlfw_InitForOpenGL(static_cast<Window*>(engine.GetSystem("window"))->GetWindowPointer(), true);
	ImGui_ImplOpenGL3_Init("#version 330");
	ImGui::StyleColorsDark();

	double lastTime = glfwGetTime();
	double currentTime = 0.0f;
	double elapsedTime;

	while (!dynamic_cast<Window*>(engine.GetSystem("window"))->windowShouldClose) {

		currentTime = glfwGetTime();
		elapsedTime = currentTime - lastTime;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		EventManager::ProcessEvents();
		dynamic_cast<Window*>(engine.GetSystem("window"))->Update();

		testField->Run();

		ImGui::Begin("Demo window");
		ImGui::Button("Hello!");
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		dynamic_cast<Window*>(engine.GetSystem("window"))->SwapBuffers();

		lastTime = currentTime;
	}
	
	testField->Terminate();

	engine.TerminateSystems();

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

#ifdef _DEBUG

	getchar();

#endif

	return EXIT_SUCCESS;
}
