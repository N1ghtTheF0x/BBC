#include "object.hpp"
#include "debug.hpp"

Object::Object(std::string tex_path)
{
    img_path = tex_path;
    std::cout << "Object[" << this << "]: Created." << std::endl;
}
void Object::update(float time,Object* obj,sf::View* v,sf::RenderWindow* rw)
{
    _update(time,obj,v,rw);
}
void Object::setUpdate(const std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> &_update)
{
    this->_update = _update;
}
std::string Object::getImagePath()
{
    return img_path;
}