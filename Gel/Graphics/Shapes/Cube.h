#pragma once
#include <Gel\Graphics\Drawable.h>
#include <Gel\Systems\GLSL.h>
#include <glm\mat4x4.hpp>
#include <Gel\Graphics\Texture.h>

namespace gel
{
	class Cube : public gel::Drawable
	{
	public:
		Cube();
		~Cube();
		void CreateCube();
		void SetPosition(glm::vec3 position);
		void Move(glm::vec3 position);
		void SetScale(glm::vec3 scale);
		void SetRotation(glm::vec3 axis, double angle);
		void Update(const glm::mat4 view, const glm::mat4 projection);
		void SetTexture(const Texture& tex) { m_Texture = tex; };
		void SetTexture(const std::string& texFile, const gel::TexParams& texParams);
		void Draw();
	private:
		
	private:
		glm::mat4 m_Model, m_View, m_Proj;
		glm::vec3 m_Position;
		glm::vec3 m_Scale;
		bool m_Dirty;
		GLSL m_Shaders;
		GLint m_ModelLocation;
		GLint m_ViewLocation;
		GLint m_ProjectionLocation;
		Texture m_Texture;
		GLint m_TextureLocation;
	};
}