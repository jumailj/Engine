#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono> // used for time related functions;




Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f,true)
{

}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture  = (Engine::Texture2D::Create("assets/textures/Checkerboard.png"));
	m_CheckerboardTexture1 = (Engine::Texture2D::Create("assets/textures/Checkerboard1.png"));
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Engine::Timestep ts)
{
	ENGINE_PROFILE_FUNCTION();


	// Update
	{
		ENGINE_PROFILE_SCOPE("CAMERA CONTROLLER:: ONUPDATE");
		m_CameraController.OnUpdate(ts);
	}



	// Render
	{
		ENGINE_PROFILE_SCOPE("RENDER: PREP");
		Engine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Engine::RenderCommand::Clear();

	}



	Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());



	for (int y = 0; y < 3; y++) {

		for (int x = 0; x < 3; x++) {

			Engine::Renderer2D::DrawQuad({ 0.4f * x, -0.4f * y }, { 0.3f, 0.3f }, { 1.7f, 0.5f, 0.3f, 1.0f });

		}
	}

	Engine::Renderer2D::DrawQuad(pos,scl,color);
	Engine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.8f }, { 10.0f, 10.0f }, m_CheckerboardTexture);



	Engine::Renderer2D::EndScene();

	if (Engine::Input::IsKeyPressed(EG_KEY_UP)) {
		pos.y += 1.2f * ts;
	}
	else if (Engine::Input::IsKeyPressed(EG_KEY_DOWN)) {
		pos.y -= 1.2f * ts;
	}

	if (Engine::Input::IsKeyPressed(EG_KEY_RIGHT)) {
		pos.x += 1.2f * ts;
	}
	else if (Engine::Input::IsKeyPressed(EG_KEY_LEFT)) {
		pos.x -= 1.2f * ts;
	}


	if (Engine::Input::IsKeyPressed(EG_KEY_L)) {
		scl.x += 1.2f * ts;
		scl.y += 1.2f * ts;
	}
	else if (Engine::Input::IsKeyPressed(EG_KEY_J)) {
		scl.x -= 1.2f * ts;
		scl.y -= 1.2f * ts;
	}

}

void Sandbox2D::OnImGuiRender()
{
	ENGINE_PROFILE_FUNCTION();

 	ImGui::Begin("Settings");
 	ImGui::ColorEdit4("Square Color", glm::value_ptr(color));



 	ImGui::End();
}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
}