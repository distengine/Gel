#pragma once
#include <SFML\Window\Mouse.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <functional>

namespace gel
{
	enum class ActionType {KEY, BUTTON};

	class RealTimeAction 
	{
	public:
		RealTimeAction();
		RealTimeAction(sf::Keyboard::Key key);
		RealTimeAction(sf::Mouse::Button button);
		~RealTimeAction();

		void SetKey(sf::Keyboard::Key key) { m_Key = key; 	m_Type = gel::ActionType::KEY; }
		void SetButton(sf::Mouse::Button button) { m_Button = button; 	m_Type = gel::ActionType::BUTTON; }
		void SetCommand(std::function<void()> command) { m_Command = command; }
	
		sf::Keyboard::Key& GetKey() { return m_Key; }
		sf::Mouse::Button& GetButton() { return m_Button; }
		ActionType& GetActionType() { return m_Type; }
		std::function<void()> GetCommand() { return m_Command; }

	private:
		std::function<void()> m_Command;
		ActionType m_Type;
		sf::Keyboard::Key m_Key;
		sf::Mouse::Button m_Button;
	};
};