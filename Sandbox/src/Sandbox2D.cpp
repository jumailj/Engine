#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono> // used for time related functions;


template<typename Fn>
class Timer
{
public:
	Timer(const char* name, Fn&& func)
		: m_Name(name), m_Func(func), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		m_Stopped = true;

		float duration = (end - start) * 0.001f;
		m_Func({ m_Name, duration });
	}
private:
	const char* m_Name;
	Fn m_Func;
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
};

#define PROFILE_SCOPE(name) Timer timer##__LINE__(name, [&](ProfileResult profileResult) { m_ProfileResults.push_back(profileResult); })



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
//	PROFILE_SCOPE("Sandbox2d::onUPdate");


	PROFILE_SCOPE("Sandbox2D::OnUpdate");

	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Engine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Engine::RenderCommand::Clear();

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
 	ImGui::Begin("Settings");
 	ImGui::ColorEdit4("Square Color", glm::value_ptr(color));


	for (auto& result : m_ProfileResults)
	{
		char label[50];
		strcpy(label, "%.3fms ");
		strcat(label, result.Name);
		ImGui::Text(label, result.Time);
	}
	m_ProfileResults.clear();


 	ImGui::End();
}

void Sandbox2D::OnEvent(Engine::Event& e)
{
	m_CameraController.OnEvent(e);
}