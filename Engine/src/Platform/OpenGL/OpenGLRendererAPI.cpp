#include "EnginePCH.h"
#include "OpenGLRendererAPI.h"

#include "glad/glad.h"

namespace Engine {

	void OpenGLRendererAPI::Init() 
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t widht, uint32_t height)
	{
		glViewport(x, y, widht, height);
	}


	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}
	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexAray)
	{

		glDrawElements(GL_TRIANGLES, vertexAray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

	}
}