#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"
#include <Engine/Window.h>

namespace Engine {

	 class ENGINE_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::shared_ptr<Window> m_Window;
		bool m_Running = true;
	};

	 // to be define in CLIENT
	 Application* CreateApplication();

}
