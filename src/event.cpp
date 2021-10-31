#include "event.hpp"

Event::Event()
{
}
Event::~Event()
{
}
void Event::onEvent(sf::Event* event)
{
	switch (event->type)
	{
		case sf::Event::GainedFocus:
			onGainedFocus();
			break;
		case sf::Event::LostFocus:
			onLostFocus();
			break;
		case sf::Event::KeyPressed:
			onKeyPressed(&event->key);
			break;
		case sf::Event::KeyReleased:
			onKeyReleased(&event->key);
			break;
		case sf::Event::MouseEntered:
			onMouseEntered();
			break;
		case sf::Event::MouseLeft:
			onMouseLeft();
			break;
		case sf::Event::MouseMoved:
			onMouseMove(&event->mouseMove);
			break;
		case sf::Event::MouseWheelScrolled:
			onMouseWheel(&event->mouseWheelScroll);
			break;
		case sf::Event::MouseButtonPressed:
			onMousePressed(&event->mouseButton);
			break;
		case sf::Event::Resized:
			onResized(&event->size);
			break;
		case sf::Event::Closed:
			onClosed();
			break;
		default:
			onOther(event);
			break;
	}
}

void Event::onGainedFocus()
{
}

void Event::onLostFocus()
{
}

void Event::onKeyPressed(sf::Event::KeyEvent* key)
{
	(void)key;
}

void Event::onKeyReleased(sf::Event::KeyEvent* key)
{
	(void)key;
}

void Event::onMouseEntered()
{
}

void Event::onMouseLeft()
{
}

void Event::onMouseMove(sf::Event::MouseMoveEvent* mouse)
{
	(void)mouse;
}

void Event::onMouseWheel(sf::Event::MouseWheelScrollEvent* mouse)
{
	(void)mouse;
}

void Event::onMousePressed(sf::Event::MouseButtonEvent* mouse)
{
	(void)mouse;
}

void Event::onResized(sf::Event::SizeEvent* size)
{
	(void)size;
}

void Event::onClosed()
{
}

void Event::onOther(sf::Event* event)
{
	(void)event;
}
