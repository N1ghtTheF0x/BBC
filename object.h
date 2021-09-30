#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <functional>

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
};

#endif // OBJECT_H
