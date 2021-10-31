#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

class Object : public sf::Sprite
{
public:
    // Creates a Object by its image path
    Object(std::string tex_path);
    // Update the Object. Use for logic per Object
    void update(float dt,Object* obj,sf::View* v,sf::RenderWindow* rw);
    // Sets the Object's update function
    void setUpdate(const std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> &_update);
    // Returns the Path of the Image
    std::string getImagePath();
private:

    std::function<void(float,Object*,sf::View*,sf::RenderWindow*)> _update;

    std::string img_path;

    std::string logic_path;
};

#endif // OBJECT_H
