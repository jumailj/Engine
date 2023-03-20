#pragma once
#include "Core.h"

#include "Events/Event.h"

#include <Engine/Window.h>
#include "Engine/LayerStack.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"

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

		inline Window& GetWindow() {return *m_Window;}

		inline static Application& Get() { return *s_Instance; }



	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

		unsigned int m_VertexArray;
		unsigned int m_VertexBuffer;
		unsigned int m_IndexBuffer;


	private:
		static Application* s_Instance;
	};

	 // to be define in CLIENT
	 Application* CreateApplication();

}
