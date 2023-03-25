#include <EnginePCH.h>
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Engine {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::None: ENGINE_CORE_ASSERT(FALSE, "RendererAPI: None is currtnly not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		ENGINE_CORE_ASSERT(false, "unknown renderere API!");
		return nullptr;
	}


	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::API::None: ENGINE_CORE_ASSERT(FALSE, "RendererAPI: None is currtnly not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}

		ENGINE_CORE_ASSERT(false, "unknown renderere API!");
		return nullptr;
	}
}