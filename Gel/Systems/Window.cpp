#include "Window.h"



gel::Window::Window()
{
}


gel::Window::~Window()
{
}

bool gel::Window::createWindow(const std::string windowName, const int xPos, const int yPos, const int width, const int height, bool fullScreen)
{
	auto style = fullScreen ? sf::Style::Fullscreen : sf::Style::Default;
	m_RenderWindow.create(sf::VideoMode(width, height), windowName, style, sf::ContextSettings(24, 8, 4, 4, 5));
	if (m_RenderWindow.isOpen())
	{
		m_RenderWindow.setPosition(sf::Vector2i(xPos, yPos));
		gladLoadGL();
		return true;
	}
	else
		return false;
}

void gel::Window::display()
{
	m_RenderWindow.display();
}

bool gel::Window::isOpen()
{
	return m_RenderWindow.isOpen();
}

void gel::Window::close()
{
	m_RenderWindow.close();
}

bool gel::Window::pollEvent(sf::Event& e)
{
	return m_RenderWindow.pollEvent(e);
}