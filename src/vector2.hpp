#ifndef VECTOR2_H
#define VECTOR2_H

#include <SFML/System/Vector2.hpp>

class Vector2 : public sf::Vector2<double>
{
private:
    double x;
    double y;
public:
    Vector2(double x,double y);
    Vector2();
    void setX(double value);
    void setY(double value);
    double getX();
    double getY();
};

#endif