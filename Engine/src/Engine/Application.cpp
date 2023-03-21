#include <EnginePCH.h>

#include "Application.h"
#include "Log.h"
#include <glad/glad.h>
#include "Input.h"


namespace Engine {

#define BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)

	 Application* Application::s_Instance = nullptr;

	 static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type) 
	 {
		 switch (type) {
			 case Engine::ShaderDataType::Float:    return GL_FLOAT;
			 case Engine::ShaderDataType::Float2:   return GL_FLOAT;
			 case Engine::ShaderDataType::Float3:   return GL_FLOAT;
			 case Engine::ShaderDataType::Float4:   return GL_FLOAT;
			 case Engine::ShaderDataType::Mat3:     return GL_FLOAT;
			 case Engine::ShaderDataType::Mat4:     return GL_FLOAT;
			 case Engine::ShaderDataType::Int:      return GL_INT;
			 case Engine::ShaderDataType::Int2:     return GL_INT;
			 case Engine::ShaderDataType::Int3:     return GL_INT;
			 case Engine::ShaderDataType::Int4:     return GL_INT;
			 case Engine::ShaderDataType::Bool:     return GL_BOOL;
		 }

		 ENGINE_CORE_ASSERT(false, "unknow shaderdata type!");
		 return 0;
	 }

	 Application::Application()
	 {
		 ENGINE_CORE_ASSERT(s_Instance, "Applicaiton already exixst");
		 s_Instance = this;
		 m_Window = std::unique_ptr<Window>(Window::Create());
		 m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		 m_ImGuiLayer = new ImGuiLayer();
		 PushOverlay(m_ImGuiLayer);

		 // vertex array;
		 // vertext buffer
		 // index buffer

		 glGenVertexArrays(1, &m_VertexArray);
		 glBindVertexArray(m_VertexArray);

		 float vertices[3 * 7] = {
			 -0.5f, -0.5f, 0.0f,    0.8f, 0.2f, 0.8f, 1.0f,
			  0.5f, -0.5f, 0.0f,    0.2f, 0.3f, 0.8f, 1.0f,
			  0.0f,  0.5f, 0.0f,    0.8f, 0.8f, 0.2f, 1.0f
		 };


		 m_VertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));


		 {
			 BufferLayout layout = {
			 {ShaderDataType::Float3, "a_Position"},
			 {ShaderDataType::Float4, "a_Color"},
			 };

			 m_VertexBuffer->SetLayout(layout);
		 }


		 uint32_t index = 0;
		 const auto& layout = m_VertexBuffer->GetLayout();

		 for (const auto& element : layout)
		 {
			 glEnableVertexAttribArray(index);
			 glVertexAttribPointer(index,
				 element.GetComponentCount(),
				 ShaderDataTypeToOpenGLBaseType(element.Type),
				 element.Normalized ? GL_TRUE : GL_FALSE,
				 layout.GetStride(),
				 (const void*)element.Offset);
			 index++;
		 }


		 uint32_t indices[3] = { 0,1,2 };
		 m_IndexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices)/ sizeof(uint32_t)));


		 std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = vec4(a_Position, 1.0);	
			}
		)";

		 std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		 m_Shader.reset(new Shader(vertexSrc, fragmentSrc));

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
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Bind();

			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();


			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

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
