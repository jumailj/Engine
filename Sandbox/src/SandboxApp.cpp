#include <Engine.h>
#include "imgui/imgui.h"

class ExampleLayer : public Engine::Layer {
public:
	ExampleLayer()
		:Layer("Example") 
	{

	}
	// mainupdate loop;
	void OnUpdate() override {
		//LOG_INFO("ExampleLayer::Update");

		if (Engine::Input::IsKeyPressed(EG_KEY_TAB)) {
			LOG_WARN("FIX NIC");
		}

			if (Engine::Input::IsMouseButtonPressed(EG_MOUSE_BUTTON_1)) {

		}
		//	LOG_ERROR("MOUSE LEFT BUTTON IS PRESSED");

	}

	// graphics;
	virtual void OnImGuiRender() override {
 		ImGui::Begin("test");
		ImGui::Text("hello world");
		ImGui::Button("number");
		ImGui::End();
	}


	// events;
	void OnEvent(Engine::Event& event) override {
		// LOG_TRACE("{0}", event);

	}
};

class Sandbox : public Engine::Application {
public:
	Sandbox() {

		 PushLayer(new ExampleLayer()); //EVENTS
		// no-more PushOverlay(new Engine::ImGuiLayer()); //IMGUI
	}

	~Sandbox() {

	}
};

Engine::Application* Engine::CreateApplication() {
	return new Sandbox();
}
