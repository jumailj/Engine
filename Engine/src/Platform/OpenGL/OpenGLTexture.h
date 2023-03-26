#pragma once

#include "Engine/Renderer/Texture.h"

namespace Engine {

	class OpenGLTexture2D : public Texture2D {
	public:
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D();

		virtual uint32_t GetWidht() const override { return m_Widht; }
		virtual uint32_t GetHeight() const override { return m_Height; }

		virtual void Bind(uint32_t slot = 0) const override;

	private:
		std::string m_Path;
		uint32_t m_Widht, m_Height;
		uint32_t m_RendererID;
	};

}