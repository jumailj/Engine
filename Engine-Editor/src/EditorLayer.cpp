#include "EditorLayer.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Engine/Core/Log.h>

namespace Engine {

	static const uint32_t s_MapWidth = 24;
	static const char* s_MapTiles = "WWWWWWWWWWWWWWWWWWWWWWWW"
		"WWWWWWWWWDDDDDDWWWWWWWWW"
		"WWDDWWWWWWWWDWWWWWWWWWWW"
		"WDDDWWWWDWWWDWWWWWWWWWWW"
		"WWWWWWWWDDDDDWWWWWWWWWWW"
		"WWWWWWWWWWWWWWWWWWWWWWWW";

	

	EditorLayer::EditorLayer()
		: Layer("EditorLayer"), m_CameraController(1280.0f / 720.0f, true)
	{

	}

	void EditorLayer::OnAttach()
	{
		ENGINE_PROFILE_FUNCTION();

		m_CheckerboardTexture1 = Engine::Texture2D::Create("assets/textures/Checkerboard2.png");
		m_CheckerboardTexture = Engine::Texture2D::Create("assets/textures/Checkerboard2.png");
		m_SprietsheetTexture = Engine::Texture2D::Create("assets/textures/sprite-sheet.png");

		m_TextureStairs = Engine::SubTexture2D::CreateFromCoords(m_SprietsheetTexture, { 1,11 }, { 128, 128 }, { 1,1 });

		m_MapWidth = s_MapWidth;
		m_MapHeight = strlen(s_MapTiles) / s_MapWidth;

		s_TextureMap['D'] = Engine::SubTexture2D::CreateFromCoords(m_SprietsheetTexture, { 6,11 }, { 128, 128 }, { 1,1 });
		s_TextureMap['W'] = Engine::SubTexture2D::CreateFromCoords(m_SprietsheetTexture, { 11,11 }, { 128, 128 }, { 1,1 });


		Engine::FrameBufferSpecification fbSpec;
		fbSpec.Width = 1280;
		fbSpec.Height = 720;
		m_FrambeBuffer = Engine::FrameBuffer::Create(fbSpec);




		m_CameraController.SetZoomLevel(5.0f);
	}

	void EditorLayer::OnDetach()
	{
		ENGINE_PROFILE_FUNCTION();
	}

	void EditorLayer::OnUpdate(Engine::Timestep ts)
	{
		ENGINE_PROFILE_FUNCTION();

		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		Engine::Renderer2D::ResetStats();
		{
			ENGINE_PROFILE_SCOPE("Renderer Prep");

			m_FrambeBuffer->Bind();


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
					Engine::Renderer2D::DrawQuad({ locX - m_MapWidth / 2.0f ,  m_MapHeight - locY - m_MapHeight / 2.0f ,   0.0f }, { 1.0f, 1.0f }, texture);
				}
			}

			Engine::Renderer2D::DrawQuad({ 25.0f, 25.0f }, { 1.0f, 1.0f }, m_CheckerboardTexture);



			Engine::Renderer2D::EndScene();
			m_FrambeBuffer->Unbind();
		}
	}

	void EditorLayer::OnImGuiRender()
	{
		ENGINE_PROFILE_FUNCTION();
		// Note: Switch this to true to enable dockspace
		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive, 
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise 
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				// Disabling fullscreen would allow the window to be moved to the front of other windows, 
				// which we can't undo at the moment without finer window depth/z control.
				//ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

				if (ImGui::MenuItem("Exit")) Engine::Application::Get().Close();
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGui::Begin("Settings");

		auto stats = Engine::Renderer2D::GetStats();
		ImGui::Text("Renderer2D Stats:");
		ImGui::Text("Draw Calls: %d", stats.DrawCall);
		ImGui::Text("Quads: %d", stats.QuadCount);
		ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
		ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

		ImGui::End();

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0, 0 });
		ImGui::Begin("Viewport");
		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		if (m_ViewPortSize != *((glm::vec2*)&viewportPanelSize))
		{
			m_FrambeBuffer->Resize((uint32_t)viewportPanelSize.x, (uint32_t)viewportPanelSize.y);
			m_ViewPortSize = { viewportPanelSize.x, viewportPanelSize.y };

			m_CameraController.OnResize(viewportPanelSize.x, viewportPanelSize.y);
		}
		uint32_t textureID = m_FrambeBuffer->GetColorAttachmentRendererID();
		ImGui::Image((void*)textureID, ImVec2{ m_ViewPortSize.x, m_ViewPortSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
		ImGui::End();
		ImGui::PopStyleVar();

		ImGui::End();
	

	}

	void EditorLayer::OnEvent(Engine::Event& e)
	{
		m_CameraController.OnEvent(e);
	}

}
