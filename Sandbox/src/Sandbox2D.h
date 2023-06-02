#pragma once

#include "Engine.h"


class Sandbox2D : public Engine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Engine::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Engine::Event& e) override;
private:
	Engine::OrthographicCameraController m_CameraController;

	// Temp
	Engine::Ref<Engine::VertexArray> m_SquareVA;
	Engine::Ref<Engine::Shader> m_FlatColorShader;

	Engine::Ref<Engine::Texture2D> m_CheckerboardTexture;
	Engine::Ref<Engine::Texture2D> m_SprietsheetTexture;
	Engine::Ref<Engine::Texture2D> m_CheckerboardTexture1;

	Engine::Ref<Engine::SubTexture2D> m_TextureStairs;
	Engine::Ref<Engine::SubTexture2D> m_TextrueGrass1;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };


	uint32_t m_MapWidth, m_MapHeight;
	std::unordered_map<char, Engine::Ref<Engine::SubTexture2D>> s_TextureMap;

};