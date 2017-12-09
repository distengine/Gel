#include "Cube.h"
#include <glm\gtc\matrix_transform.hpp>

gel::Cube::Cube() : m_Dirty(true), m_Model(1)
{
}

gel::Cube::~Cube()
{
}

void gel::Cube::CreateCube()
{
	std::vector<glm::vec3> positions = 
	{
		// front
		glm::vec3(-1.0, -1.0,  1.0),
		glm::vec3( 1.0, -1.0,  1.0),
		glm::vec3( 1.0,  1.0,  1.0),
		glm::vec3(-1.0,  1.0,  1.0),
		// top
		glm::vec3(-1.0,  1.0,  1.0),
		glm::vec3( 1.0,  1.0,  1.0),
		glm::vec3( 1.0,  1.0, -1.0),
		glm::vec3(-1.0,  1.0, -1.0),
		// back
		glm::vec3( 1.0, -1.0, -1.0),
		glm::vec3(-1.0, -1.0, -1.0),
		glm::vec3(-1.0,  1.0, -1.0),
		glm::vec3( 1.0,  1.0, -1.0),
		// bottom
		glm::vec3(-1.0, -1.0, -1.0),
		glm::vec3( 1.0, -1.0, -1.0),
		glm::vec3( 1.0, -1.0,  1.0),
		glm::vec3(-1.0, -1.0,  1.0),
		// left
		glm::vec3(-1.0, -1.0, -1.0),
		glm::vec3(-1.0, -1.0,  1.0),
		glm::vec3(-1.0,  1.0,  1.0),
		glm::vec3(-1.0,  1.0, -1.0),
		// right
		glm::vec3(1.0, -1.0,  1.0),
		glm::vec3(1.0, -1.0, -1.0),
		glm::vec3(1.0,  1.0, -1.0),
		glm::vec3(1.0,  1.0,  1.0)
	};

	std::vector<glm::vec2> uv =
	{
		glm::vec2(0, 0),
		glm::vec2(1, 0),
		glm::vec2(1, 1),
		glm::vec2(0, 1),
	};

	std::initializer_list<GLubyte> indicies = 
	{
		// front
		0,  1,  2,
		2,  3,  0,
		// top
		4,  5,  6,
		6,  7,  4,
		// back
		8,  9, 10,
		10, 11,  8,
		// bottom
		12, 13, 14,
		14, 15, 12,
		// left
		16, 17, 18,
		18, 19, 16,
		// right
		20, 21, 22,
		22, 23, 20,
	};

	gel::Vertex vert;
	int uvCounter = 0;
	for (int i = 0; i < positions.size(); i++)
	{
		vert.Position = positions[i];
		vert.UV = uv[uvCounter];
		uvCounter++;
		if (uvCounter > 3)
			uvCounter = 0;
		this->m_Vertices.push_back(vert);
	}
	this->m_Indices = indicies;
	this->CreateBuffers();
	m_Shaders.addShader(GL_VERTEX_SHADER, "Shaders/Cube.vert");
	m_Shaders.addShader(GL_FRAGMENT_SHADER, "Shaders/Cube.frag");
	m_Shaders.linkShaders();

	m_ModelLocation = m_Shaders.getUniformLocation("Model");
	m_ViewLocation = m_Shaders.getUniformLocation("View");
	m_ProjectionLocation = m_Shaders.getUniformLocation("Projection");

	m_Texture.createTexture(TexParams(GL_TEXTURE_2D, GL_CLAMP_TO_BORDER, GL_TEXTURE_MIN_FILTER, GL_NEAREST, GL_TEXTURE_MAG_FILTER, GL_NEAREST), "Textures/container.jpg");
	m_TextureLocation = m_Shaders.getUniformLocation("texture1");
}

void gel::Cube::SetPosition(glm::vec3 position)
{
	m_Dirty = true;
	//m_Model = glm::translate(m_Model, position);
	m_Model[3][0] = position.x;
	m_Model[3][1] = position.y;
	m_Model[3][2] = position.z;
}

void gel::Cube::Move(glm::vec3 position)
{
	m_Dirty = true;
	m_Model = glm::translate(m_Model, position);
}

void gel::Cube::SetScale(glm::vec3 scale)
{
	m_Dirty = true;
	m_Model = glm::scale(m_Model, scale);
}

void gel::Cube::SetRotation(glm::vec3 axis, double angle)
{
	m_Dirty = true;
	m_Model = glm::rotate(m_Model, glm::radians(static_cast<float>(angle)), axis);
}

void gel::Cube::Update(const glm::mat4 view, const glm::mat4 projection)
{
	m_Shaders.use();
	m_Shaders.glUniform(m_ViewLocation, view);
	m_Shaders.glUniform(m_ProjectionLocation, projection);
	m_Shaders.unuse();
}

void gel::Cube::SetTexture(const std::string & texFile, const gel::TexParams& texParams)
{
	m_Texture.createTexture(texParams, texFile);
}

void gel::Cube::Draw()
{
	m_Shaders.use();
	glActiveTexture(GL_TEXTURE0);
	m_Texture.bind();
	if (m_Dirty)
	{	
		m_Shaders.glUniform(m_ModelLocation, m_Model);
		m_Shaders.glUniform(m_TextureLocation, 0);
		m_Dirty = false;
	}
	Drawable::Draw();
	m_Texture.unbind();
	m_Shaders.unuse();
}