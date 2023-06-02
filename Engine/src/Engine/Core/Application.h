#pragma once
#include "Core.h"

#include "Engine/Events/Event.h"

#include <Engine/Core/Window.h>
#include "Engine/Core/LayerStack.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"

#include "Engine/Core/Timestep.h"

#include "Engine/ImGui/ImGuiLayer.h"


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

		 inline Window& GetWindow() { return *m_Window; }

		 void Close();

		 inline static Application& Get() { return *s_Instance; }
	 private:
		 bool OnWindowClose(WindowCloseEvent& e);
		 bool OnWindowResize(WindowResizeEvent& e);

	 private:

		 std::unique_ptr<Window> m_Window;
		 ImGuiLayer* m_ImGuiLayer;

		 bool m_Running = true;
		 bool m_Minimized = false;

		 LayerStack m_LayerStack;
		 float m_LastFrameTime = 0.0f;
		 

	 private:
		 static Application* s_Instance;
	 };

	 // to be define in CLIENT
	 Application* CreateApplication();

}
