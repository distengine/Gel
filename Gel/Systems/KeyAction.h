#pragma once
#include <SFML\Window\Event.hpp>
#include <functional>

namespace gel
{
	// Enumify the key action (KeyDown, KeyUp, KeyHeld)
	enum class Action {KeyDown = sf::Event::EventType::KeyPressed, KeyUp = sf::Event::EventType::KeyReleased, WheelMoved = sf::Event::EventType::MouseWheelMoved};
	// A key action binds a key with a command
	class KeyAction
	{
	public:
		KeyAction() {};
		KeyAction(sf::Keyboard::Key key) { m_Key = key; }
		KeyAction(gel::Action action) { m_Action = action; }
		KeyAction(sf::Keyboard::Key key, gel::Action action) { m_Key = key; m_Action = action; }
		void SetKey(sf::Keyboard::Key key) { m_Key = key; }
		void SetButton(sf::Mouse::Button but) { m_Button = but; }
		void SetAction(gel::Action action) { m_Action = action; }
		void SetCommand(std::function<void()> command) { m_Command = command; }
		void SetDoubleCommand(std::function<void(double)> command) { m_DoubleCommand = command; }
		sf::Keyboard::Key& GetKey() { return m_Key; }
		sf::Mouse::Button& GetButton() { m_Button; }
		gel::Action& GetAction() { return m_Action; }
		std::function<void()> GetCommand() { return m_Command; }
		std::function<void(double)> GetDoubleCommand() { return m_DoubleCommand; }
	private:
		sf::Keyboard::Key m_Key;
		sf::Mouse::Button m_Button;
		gel::Action m_Action;
		std::function<void()> m_Command;
		std::function<void(double)> m_DoubleCommand;
	};
}