#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <glad\glad.h>
#include <SFML\Window\Event.hpp>

namespace gel
{
	class Window
	{
	public:
		Window();
		~Window();

		bool createWindow(const std::string windowName, const int xPos, const int yPos, const int width, const int height, bool fullScreen);
		void display();
		bool isOpen();
		void close();
		bool pollEvent(sf::Event& e);
	private:

	private:
		sf::RenderWindow m_RenderWindow;
	};
}