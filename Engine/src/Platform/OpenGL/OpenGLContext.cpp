#include "EnginePCH.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Engine {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		ENGINE_CORE_ASSERT(windowHandle, "window handel is null");

	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ENGINE_CORE_ASSERT(status, "faile to initalize GLAD!");

		LOG_CORE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
		LOG_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
		LOG_CORE_INFO("Version: {0}", glGetString(GL_VERSION));

	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}