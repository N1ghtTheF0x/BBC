#ifndef EVENT_H
#define EVENT_H

#include <SFML/Window/Event.hpp>

class Event
{
public:
    Event();

    virtual ~Event();

    virtual void onEvent(sf::Event* event);
    virtual void onGainedFocus();
    virtual void onLostFocus();
    virtual void onKeyPressed(sf::Event::KeyEvent* key);
    virtual void onKeyReleased(sf::Event::KeyEvent* key);
    virtual void onMouseEntered();
    virtual void onMouseLeft();
    virtual void onMouseMove(sf::Event::MouseMoveEvent* mouse);
    virtual void onMouseWheel(sf::Event::MouseWheelScrollEvent* mouse);
    virtual void onMousePressed(sf::Event::MouseButtonEvent* mouse);
    virtual void onResized(sf::Event::SizeEvent* size);
    virtual void onClosed();
    virtual void onOther(sf::Event* event);
};

#endif // EVENT_H
