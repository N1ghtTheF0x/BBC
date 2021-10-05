#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>


class Object : public sf::Sprite
{
public:
    Object(std::string &tex_path);

    bool loadFromFile(const std::string& path);
    sf::Texture *getTexture();
    bool isReady();
    void update(float dt,Object* obj,sf::View* v,sf::RenderWindow* rw);

    void setUpdate(const std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> &_update);

private:
    sf::Texture tex;
    bool hasTexture;

    std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> _update;
};

#endif // OBJECT_H
