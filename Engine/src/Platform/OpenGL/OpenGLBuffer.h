#pragma once

#include "Engine/Renderer/Buffer.h"


namespace Engine {

	class OpenGLVertexBuffer : public VertexBuffer {
	public:

		OpenGLVertexBuffer(float* vertices, uint32_t size);
		 ~OpenGLVertexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

	private:

		uint32_t  m_RendererID;
	};


	class OpenGLIndexBuffer : public IndexBuffer {
	public:

		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual int32_t GetCount() const {
			return m_Count;
		}

	private:

		uint32_t  m_RendererID;
		uint32_t  m_Count;
	};



}