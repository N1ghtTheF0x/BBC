#include "object.h"
#include "debug.h"

Object::Object(std::string &tex_path)
{
    std::cout << "Object[" << this << "]: Created." << std::endl;
    tex = sf::Texture();
    hasTexture = loadFromFile(tex_path);
    sf::Vector2u img_size = tex.getSize();
    sf::IntRect size(0,0,img_size.x,img_size.y);
    

    std::cout << "Object[" << this << "]: Is Ready? " << (hasTexture ? "yes" : "no") << std::endl;
    _update = [](float time,Object* obj,sf::View* v,sf::RenderWindow* rw)
    {
        (void)time;
        (void)obj;
        (void)v;
        (void)rw;
    };
}
bool Object::loadFromFile(const std::string& text)
{
    return tex.loadFromFile(text);
}
sf::Texture *Object::getTexture()
{
    return &tex;
}

bool Object::isReady()
{
    return hasTexture;
}
void Object::update(float time,Object* obj,sf::View* v,sf::RenderWindow* rw)
{
    _update(time,obj,v,rw);
}
void Object::setUpdate(const std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> &_update)
{
    this->_update = _update;
}