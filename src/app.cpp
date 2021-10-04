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
    try
    {
        Debug::print("onInit(): Window");
        window = new sf::RenderWindow();
        window->create(sf::VideoMode(1280,720),"Skoge");
        view = new sf::View(sf::FloatRect(0,0,1280,720));
        window->setView(*view);
        Debug::print("onInit(): Test Images Path");
        std::string testpng = mgr.getImage("test.png");
        std::string test2png = mgr.getImage("test2.png");
        Debug::print("onInit(): Test Objects");

        Object testobj(testpng);
        Object test2obj(test2png);

        testobj.update = [](float delta,Object *obj,sf::View *v,sf::RenderWindow *rw)
        {
            float spd = 50;
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
        };

        test2obj.setPosition(500,500);

        objects.push_back(testobj);
        objects.push_back(test2obj);

        std::cout << &objects[0] << " | " << &objects[1] << std::endl;
        std::cout << "objects#size: " << objects.size() << std::endl;
    }
    catch(const std::exception& e)
    {
        Debug::print(e.what());
        return false;
    }
    Debug::print("onInit(): End");
    return true;
}
void App::onEvent(sf::Event* event)
{
    Event::onEvent(event);
}
void App::onLoop()
{
    for (size_t i = 0; i < objects.size(); i++)
    {
        Object obj = objects.at(i);
        obj.update(p_delta.asSeconds(),&obj,view,window);
        objects[i] = obj;

    }
}
void App::onRender()
{
    window->clear();
    for (size_t i = 0; i < objects.size(); i++)
    {
        Object obj = objects.at(i);
        if(!obj.isReady()) continue;
        obj.setTexture(*obj.getTexture());
        window->draw(obj);
    }
    window->display();
}
void App::onCleanup()
{
    Debug::print("onCleanup()");
    window->close();
}
void App::onClosed()
{
    running = false;
}