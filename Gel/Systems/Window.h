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
		void fullScreen();
		sf::RenderWindow& GetWindowRef() { return m_RenderWindow; }
		sf::Vector2u GetSize() { return m_RenderWindow.getSize(); }
	private:

	private:
		sf::RenderWindow m_RenderWindow;
		std::string m_Title;
		sf::Vector2i m_Size, m_Pos;
		bool m_FullScreen;
	};
}