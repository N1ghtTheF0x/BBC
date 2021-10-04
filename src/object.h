#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <stack>

#include "addons/addon.h"

class Object : public sf::Sprite
{
public:
    Object(std::string &tex_path);

    bool loadFromFile(const std::string& path);
    sf::Texture *getTexture();
    bool isReady();
    std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> update;

private:
    sf::Texture tex;
    bool hasTexture;
    std::stack<A*> addons;
};

#endif // OBJECT_H
