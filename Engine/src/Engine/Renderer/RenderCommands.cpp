#include "EnginePCH.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace Engine {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}