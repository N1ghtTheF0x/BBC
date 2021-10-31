#ifndef APP_H
#define APP_H

#include <vector>
#include <stack>

#include "object.hpp"
#include "event.hpp"
#include "mgr.hpp"

class App : public Event
{
public:
    App(int argc,char** argv);
    // Functions that should execute first. Returns the Program Exit Code
    int onExecute();
    // Initailzie the App
    bool onInit();
    // Execute on SFML Event
    void onEvent(sf::Event* event);
    // The Update Loop, updates Objects. Not FPS based!
    void onLoop();
    // Draws the Objects onto the Screen
    void onRender();
    // Clean up the Trash in the Program
    void onCleanup();
    // When User exits the Program (X,Alt+F4,Task Manager,etc)
    void onClosed();
    // Get the Path of the root folder
    std::string getPath();
private:
    // Is the App running?
    bool running;
    // The Window of the App
    sf::RenderWindow* window;
    // The Camera
    sf::View* view;
    // A list containing Objects to draw/update
    std::vector<Object> objects;
    // Arguments from the Command Line
    std::vector<std::string> argv;
    // Past Delta
    sf::Time p_delta;
    // Last Delta
    sf::Time l_delta;
    // Debugging Stuff
    bool debug;
    // The Asset Manager. Get Paths to files
    Manager mgr;
};

#endif // APP_H
