#include "app.h"
#include "debug.h"
#include <algorithm>

App::App(int _argc,char** _argv): Event()
{
    argv = std::vector<std::string>(_argv,_argv+_argc);
    window = NULL;
    view = NULL;
    objects = std::vector<Object>();
    running = true;
    debug = std::find(argv.begin(),argv.end(),"-debug") != argv.end();
    Debug::print("App(): Created");
    mgr = Manager(getPath());
}

std::string App::getPath()
{
    char sep = '/';
    #ifdef _WIN32
        sep = '\\';
    #endif
    std::string path = argv[0];
    size_t i = path.rfind(sep,path.length());
    if(i != std::string::npos)
    {
        return path.substr(0,i) + sep;
    }
    return "";
}

int App::onExecute()
{
    if(onInit() == false) return -1;
    sf::Clock c;
    sf::Event event;
    Debug::print("onExecute()");
    while(running)
    {
        l_delta = p_delta;
        p_delta = c.restart();
        while(window->pollEvent(event))
        {
            onEvent(&event);
        }
        onLoop();
        onRender();
    }
    onCleanup();
    return 0;
}
bool App::onInit()
{
    Debug::print("onInit(): Start");
    // Trying to Load everything...
    try
    {
        Debug::print("onInit(): Window");
        window = new sf::RenderWindow(); // Make Window Object
        window->create(sf::VideoMode(1280,720),"Skoge"); // Create the visible Window
        view = new sf::View(sf::FloatRect(0,0,1280,720)); // Make Camera Object
        window->setView(*view); // Set the Camera Object
        Debug::print("onInit(): Test Images Path");
        std::string testpng = mgr.getImage("test.png"); // Test image
        std::string test2png = mgr.getImage("test2.png"); // Test image 2
        Debug::print("onInit(): Test Objects");

        Object testobj(testpng); // Basic test Object with WASD movement
        Object test2obj(test2png); // Still Object

        testobj.setUpdate([](float delta,Object *obj,sf::View *v,sf::RenderWindow *rw) // Remember to use Delta for movement calculations
        {
            float spd = 100;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                obj->move(0,-spd*delta);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                obj->move(0,spd*delta);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                obj->move(-spd*delta,0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                obj->move(spd*delta,0);
            }
        });

        test2obj.setPosition(500,500); // Sets the Position somewhere...
        // Add these Objects to the Array
        objects.push_back(testobj);
        objects.push_back(test2obj);

        std::cout << &objects[0] << " | " << &objects[1] << std::endl;
        std::cout << "objects#size: " << objects.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        // Something went wrong!
        Debug::print(e.what());
        return false;
    }
    Debug::print("onInit(): End");
    // Done Loading
    return true;
}
void App::onEvent(sf::Event* event)
{
    Event::onEvent(event); // Wow, such Event o_o
}
void App::onLoop()
{
    for (size_t i = 0; i < objects.size(); i++) // Go through every Object...
    {
        Object obj = objects.at(i); // Get it
        obj.update(p_delta.asSeconds(),&obj,view,window); // Update it
        objects[i] = obj; // Set it back? This shouldn't be here...
    }
}
void App::onRender()
{
    window->clear(); // Clear the Canvas
    for (size_t i = 0; i < objects.size(); i++) // Every Object
    {
        Object obj = objects.at(i); // Get da Object
        if(!obj.isReady()) continue; // Don't draw if not ready
        obj.setTexture(*obj.getTexture()); // Set the Texture. Maybe make a Texture manager for better loading?
        window->draw(obj); // Just draw it
    }
    window->display(); // And display all
}
void App::onCleanup()
{
    // Delete, destroy stuff here. Free up Memory
    Debug::print("onCleanup()");
    window->close(); 
}
void App::onClosed()
{
    running = false; // Not running anymore
}