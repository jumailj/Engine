#include "EnginePCH.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace Engine {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}