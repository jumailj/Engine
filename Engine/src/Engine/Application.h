#pragma once
#include "Core.h"

#include "Events/Event.h"

#include <Engine/Window.h>
#include "Engine/LayerStack.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"


namespace Engine {

	 class ENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);



	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::shared_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	 // to be define in CLIENT
	 Application* CreateApplication();

}
