#pragma once
#include <glad\glad.h>
#include <string>

namespace gel {

	struct TexParams
	{
		TexParams(GLenum target, GLenum wrap, GLint texWrap, GLenum filMin, GLint minFil, GLenum filMag, GLint magFil);
		GLenum Target, Wrap, FilterMin, FilterMag;
		GLint TexWrap, MinFilter, MagFilter;
	};

	class Texture
	{
	public:
		Texture();
		~Texture();
		void createTexture(const TexParams param, const std::string texFile);
		GLuint& getTexture();
		void bind();
		void unbind();
	private:
		GLuint m_Texture;
		GLenum m_Target;
	};
}