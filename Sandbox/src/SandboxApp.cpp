#include <Engine.h>

class ExampleLayer : public Engine::Layer {
public:
	ExampleLayer()
		:Layer("Example") 
	{

	}
	void OnUpdate() override {
		//LOG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Engine::Event& event) override {
		LOG_TRACE("{0}", event);
	}

};

class Sandbox : public Engine::Application {
public:
	Sandbox() {

		PushLayer(new ExampleLayer());
		PushOverlay(new Engine::ImGuiLayer());
	}

	~Sandbox() {

	}
};


Engine::Application* Engine::CreateApplication() {
	return new Sandbox();
}
