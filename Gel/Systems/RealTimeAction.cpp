#include "RealTimeAction.h"

gel::RealTimeAction::RealTimeAction()
{
}

gel::RealTimeAction::RealTimeAction(sf::Keyboard::Key key)
{
	m_Key = key;
	m_Type = gel::ActionType::KEY;
}

gel::RealTimeAction::RealTimeAction(sf::Mouse::Button button)
{
	m_Button = button;
	m_Type = gel::ActionType::BUTTON;
}

gel::RealTimeAction::~RealTimeAction()
{
}