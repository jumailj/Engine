#pragma once

#include "Engine.h"

namespace Engine {

	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;

	private:
		Engine::OrthographicCameraController m_CameraController;

		// Temp
		Ref<Engine::VertexArray> m_SquareVA;
		Ref<Engine::Shader> m_FlatColorShader;
		Ref<Engine::FrameBuffer> m_FrambeBuffer;


		Ref<Engine::Texture2D> m_CheckerboardTexture;
		Ref<Engine::Texture2D> m_SprietsheetTexture;
		Ref<Engine::Texture2D> m_CheckerboardTexture1;

		Ref<Engine::SubTexture2D> m_TextureStairs;
		Ref<Engine::SubTexture2D> m_TextrueGrass1;


		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };

		//framebuffer; (importatn)
		glm::vec2 m_ViewPortSize;

		uint32_t m_MapWidth, m_MapHeight;
		std::unordered_map<char, Engine::Ref<Engine::SubTexture2D>> s_TextureMap;


	};
}

