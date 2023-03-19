#include <EnginePCH.h>

#include "Application.h"
#include "Log.h"
#include <glad/glad.h>
#include "Input.h"


namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)

	 Application* Application::s_Instance = nullptr;


	Application::Application()
	{
		ENGINE_CORE_ASSERT(s_Instance, "Applicaiton already exixst");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}


	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		// ->  LOG_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {

			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}


	void Application::Run() {

		while (m_Running) 
		{
			glClearColor(0.19f, 0.85f, 0.45f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

// 			auto [x, y] = Engine::Input::GetMousePosition();
// 			LOG_CORE_INFO("{0}, {1} :: ", x, y);

			

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

}
