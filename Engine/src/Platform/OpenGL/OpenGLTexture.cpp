#include "EnginePCH.h"
#include "OpenGLTexture.h"

#include "stb_image.h"
#include <glad/glad.h>



namespace Engine {
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		: m_Path{path}
	{
		int widht, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data =  stbi_load(path.c_str(),&widht, &height, &channels, 0 );
		ENGINE_CORE_ASSERT(data, "Failed to load image!");

		m_Widht = widht;
		m_Height = height;

		GLenum internalFormat = 0, dataFormat = 0;
		if (channels == 4) {
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if (channels == 3) {
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}

		ENGINE_CORE_ASSERT(internalFormat && dataFormat, " fromat not supported!");



		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, internalFormat, m_Widht, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		// glTextureParameteri(m_RendererID, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Widht, m_Height, dataFormat, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data); // dealocate
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}
}