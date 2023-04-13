#include <EnginePCH.h>

#include "RendererAPI.h"
#include <Platform/OpenGL/OpenGLRendererAPI.h>

namespace Engine {
	
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	
	Scope<RendererAPI> RendererAPI::Create()
	{
		
		switch (s_API)
		{
		case RendererAPI::API::None:    ENGINE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLRendererAPI>();
		}

		ENGINE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

		
	}
	


}