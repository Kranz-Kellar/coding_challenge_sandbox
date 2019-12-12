
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

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui_ImplGlfw_InitForOpenGL(engine.window->GetWindowPointer(), true);
	ImGui_ImplOpenGL3_Init("#version 330");
	ImGui::StyleColorsDark();

	ChunkRenderer* chunkRenderer = new ChunkRenderer(dynamic_cast<IRenderer*>(engine.GetSystem("renderer")));

	std::shared_ptr<Shader> shader = engine.resourceManager->LoadShaderWithName("BaseShader","res/shaders/base_vector_shader.vs","res/shaders/base_fragment_shader.fs");

	std::shared_ptr<Texture2D> texture = engine.resourceManager->LoadTextureWithName("BaseTexture","res/textures/test.png");

	std::shared_ptr<Sprite> sprite = engine.resourceManager->GenerateSpriteFromTextureWithShader("Sprite", "BaseTexture", "BaseShader");

	std::vector<std::shared_ptr<Block>> testBlocks;
	for (unsigned int i = 0; i < 1; i++) {
		Transform transform(nullptr);
		transform.Translate(0.0f, 0.0f, 10.0f);
		testBlocks.push_back(std::make_shared<Block>(B_DIRT, transform, sprite));
	}

	Chunk* testChunk = new Chunk(testBlocks);

	OpenGLDrawData* drawData = new OpenGLDrawData();
	drawData->modelMatrix = glm::mat4(1.0f);
	drawData->shader = shader;
	drawData->texture = texture;
	drawData->typeOfDraw = GL_STATIC_DRAW;


	while (!dynamic_cast<Window*>(engine.GetSystem("window"))->windowShouldClose) {

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		EventManager::ProcessEvents();
		dynamic_cast<Window*>(engine.GetSystem("window"))->Update();

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		glm::translate(drawData->modelMatrix, glm::vec3(x, y, z));
		dynamic_cast<IRenderer*>(engine.GetSystem("renderer"))->Draw2DObject(drawData);


		

		ImGui::Begin("Demo window");
		ImGui::SliderFloat("X", &x, -10.0f, 10.0f);
		ImGui::SliderFloat("Y", &y, -10.0f, 10.0f);
		ImGui::SliderFloat("Z", &z, -10.0f, 10.0f);
		ImGui::TextUnformatted(std::to_string(x).c_str());
		
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		dynamic_cast<Window*>(engine.GetSystem("window"))->SwapBuffers();
	}
	
	//testField->Terminate();

	engine.TerminateSystems();

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

#ifdef _DEBUG

	getchar();

#endif

	return EXIT_SUCCESS;
}
