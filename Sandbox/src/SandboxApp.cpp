#include <Engine.h>



class ExampleLayer : public Engine::Layer {
public:
	ExampleLayer()
		:Layer("Example") 
	{

	}
	void OnUpdate() override {
		//LOG_INFO("ExampleLayer::Update");

		if (Engine::Input::IsKeyPressed(EG_KEY_TAB))
			LOG_INFO("tab key is pressed");

		if (Engine::Input::IsMouseButtonPressed(EG_MOUSE_BUTTON_1))
			LOG_ERROR("MOUSE LEFT BUTTON IS PRESSED");

	}

	void OnEvent(Engine::Event& event) override {
		// LOG_TRACE("{0}", event);
	}

};

class Sandbox : public Engine::Application {
public:
	Sandbox() {

		 PushLayer(new ExampleLayer()); //EVENTS
		 PushOverlay(new Engine::ImGuiLayer()); //IMGUI
	}

	~Sandbox() {

	}
};

Engine::Application* Engine::CreateApplication() {
	return new Sandbox();
}
