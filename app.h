#ifndef APP_H
#define APP_H

#include <vector>
#include "object.h"
#include "event.h"

class App : public Event
{
public:
    App(int argc,char** argv);

    int onExecute();

    bool onInit();

    void onEvent(sf::Event* event);

    void onLoop();

    void onRender();

    void onCleanup();

    void onClosed();

    std::string getPath();
private:
    bool running;
    sf::RenderWindow* window;
    sf::View* view;

    std::vector<Object> objects;

    std::vector<std::string> argv;

    sf::Time p_delta;
    sf::Time l_delta;

    bool debug;
};

#endif // APP_H
