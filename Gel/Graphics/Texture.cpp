#include "Texture.h"
#include <SFML\Graphics\Image.hpp>

gel::Texture::Texture() : m_Texture(0), m_Target(0)
{
}

gel::Texture::~Texture()
{
	glDeleteTextures(1, &m_Texture);
}

void gel::Texture::createTexture(const TexParams param, const std::string texFile)
{
	m_Target = param.Target;
	glCreateTextures(m_Target, 1, &m_Texture);
	glBindTexture(m_Target, m_Texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(param.Target, GL_TEXTURE_WRAP_S, param.Wrap);
	glTexParameteri(param.Target, GL_TEXTURE_WRAP_T, param.Wrap);
	glTexParameteri(param.Target, param.FilterMin, param.MinFilter);
	glTexParameteri(param.Target, param.FilterMag, param.MagFilter);
	sf::Image img;
	if (img.loadFromFile(texFile))
	{
		img.flipVertically();
		glTexImage2D(param.Target, 0, GL_RGBA, img.getSize().x, img.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
		glGenerateMipmap(param.Target);
	}
}

GLuint & gel::Texture::getTexture()
{
	return m_Texture;
}

void gel::Texture::bind()
{
	glBindTexture(m_Target, m_Texture);
}

void gel::Texture::unbind()
{
	glBindTexture(m_Target, 0);
}

gel::TexParams::TexParams(GLenum target, GLenum wrap, GLint texWrap, GLenum filMin, GLint minFil, GLenum filMag, GLint magFil)
{
	Target = target;
	Wrap = wrap;
	TexWrap = texWrap;
	FilterMin = filMin;
	MinFilter = minFil;
	FilterMag = filMag;
	MagFilter = magFil;
}