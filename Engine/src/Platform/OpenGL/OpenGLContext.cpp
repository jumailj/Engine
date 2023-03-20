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

	}
	void OpenGLContext::SwapBuffers()
	{

		glBegin(GL_TRIANGLES);
		glColor3f(0.84, 0.14, 0.19);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();

		glfwSwapBuffers(m_WindowHandle);
	}
}