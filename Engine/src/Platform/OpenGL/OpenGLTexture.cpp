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

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, GL_RGB8, m_Widht, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Widht, m_Height, GL_RGB, GL_UNSIGNED_BYTE, data);

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