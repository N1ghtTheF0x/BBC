#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>


class Object : public sf::Sprite
{
public:
    // Creates a Object by its image path
    Object(std::string &tex_path);
    // Load a image from a file
    bool loadFromFile(const std::string& path);
    // Returns the Texture of the Object
    sf::Texture *getTexture();
    // Check if the Object is ready to use
    bool isReady();
    // Update the Object. Use for logic per Object
    void update(float dt,Object* obj,sf::View* v,sf::RenderWindow* rw);
    // Sets the Object's update function
    void setUpdate(const std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> &_update);

private:
    // The Texture of the Sprite
    sf::Texture tex;
    // Has this Sprite a valid Texture?
    bool hasTexture;

    std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> _update;
};

#endif // OBJECT_H
