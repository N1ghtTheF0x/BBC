#include "object.h"
#include "debug.h"

Object::Object(std::string &tex_path)
{
    std::cout << "Object[" << this << "]: Created." << std::endl;
    tex = sf::Texture();
    hasTexture = loadFromFile(tex_path);
    std::cout << "Object[" << this << "]: Is Ready? " << (hasTexture ? "yes" : "no") << std::endl;
    update = [](float time,Object* obj,sf::View* v,sf::RenderWindow* rw)
    {

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