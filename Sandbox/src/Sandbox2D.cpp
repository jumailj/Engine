#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Engine/Core/Log.h>

static const uint32_t s_MapWidth = 24;
static const char* s_MapTiles = "WWWWWWWWWWWWWWWWWWWWWWWW"
								"WWWWWWWWWDDDDDDWWWWWWWWW"
								"WWWWWWWWWWWWDWWWWWWWWWWW"
								"WWWWWWWWDWWWDWWWWWWWWWWW"
								"WWWWWWWWDDDDDWWWWWWWWWWW"
								"WWWWWWWWWWWWWWWWWWWWWWWW";


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, false)
{

}

void Sandbox2D::OnAttach()
{
	ENGINE_PROFILE_FUNCTION();

	m_CheckerboardTexture1 = Engine::Texture2D::Create("assets/textures/Checkerboard2.png");
	m_CheckerboardTexture = Engine::Texture2D::Create("assets/textures/Checkerboard2.png");
 	m_SprietsheetTexture = Engine::Texture2D::Create("assets/textures/sprite-sheet.png");

	m_TextureStairs = Engine::SubTexture2D::CreateFromCoords(m_SprietsheetTexture, { 1,11 }, { 128, 128 }, {1,1});

	m_MapWidth = s_MapWidth;
	m_MapHeight = strlen(s_MapTiles)/ s_MapWidth;	

	s_TextureMap['D'] = Engine::SubTexture2D::CreateFromCoords(m_SprietsheetTexture, {6,11}, {128, 128}, {1,1});
	s_TextureMap['W'] = Engine::SubTexture2D::CreateFromCoords(m_SprietsheetTexture, { 11,11 }, { 128, 128 }, { 1,1 });


	m_CameraController.SetZoomLevel(5.0f);
}

void Sandbox2D::OnDetach()
{
	ENGINE_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Engine::Timestep ts)
{
	ENGINE_PROFILE_FUNCTION();

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Engine::Renderer2D::ResetStats();
	{
		ENGINE_PROFILE_SCOPE("Renderer Prep");


		Engine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Engine::RenderCommand::Clear();
	}

	{

		static float rotation = 0.0f;
		rotation += ts * 20.0f;

		static float x = -2.0f;
		static float y = 0.0f;

		if (Engine::Input::IsKeyPressed(EG_KEY_LEFT)) {
			x += 1.0f * ts;
		}

		if (Engine::Input::IsKeyPressed(EG_KEY_RIGHT)) {
			x -= 1.0f * ts;
		}

		if (Engine::Input::IsKeyPressed(EG_KEY_DOWN)) {
			y += 1.0f * ts;
		}

		if (Engine::Input::IsKeyPressed(EG_KEY_UP)) {
			y -= 1.0f * ts;
		}

		ENGINE_PROFILE_SCOPE("Renderer Draw");
		Engine::Renderer2D::BeginScene(m_CameraController.GetCamera());
		// Engine::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		// Engine::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		// Engine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	//	 Engine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture1, 10.0f);

	//	 Engine::Renderer2D::DrawRotatedQuad({ x, y, 0.0f }, { 1.0f, 1.0f }, 0.0, m_CheckerboardTexture, 1.0f);


		for (uint32_t y = 0; y < m_MapHeight; y++) {
	
			for (uint32_t x = 0; x < m_MapWidth; x++) {

				char tileType = s_MapTiles[x + y * m_MapWidth];
				Engine::Ref<Engine::SubTexture2D> texture;

				if (s_TextureMap.find(tileType) != s_TextureMap.end()) {
					//LOG_TRACE("TRACE: {0}", s_TextureMap[tileType]);
					texture = s_TextureMap[tileType];
				}
				else {
					texture = m_TextrueGrass1;
				}

				 float locX = x;
				 float locY = y;

				//Engine::Renderer2D::DrawQuad({ x - m_MapWidth/2.0f, m_MapHeight- y /2.0f,   0.0f }, { 1.0f, 1.0f }, texture);
				Engine::Renderer2D::DrawQuad({ locX -m_MapWidth/2.0f ,  m_MapHeight- locY- m_MapHeight /2.0f ,   0.0f }, { 1.0f, 1.0f }, texture);
			}
		}

		Engine::Renderer2D::DrawQuad({ 25.0f, 25.0f }, { 1.0f, 1.0f }, m_CheckerboardTexture);

		
		
		Engine::Renderer2D::EndScene();

	}
}

void Sandbox2D::OnImGuiRender()
{
	ENGINE_PROFILE_FUNCTION();


	ImGui::Begin("Settings");

	auto stats = Engine::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCall);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

    ImGui::End();

}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
}