#include "vector2.hpp"

Vector2::Vector2()
{
    x = 0;
    y = 0;
}

Vector2::Vector2(double _x,double _y)
{
    x = _x;
    y = _y;
}

double Vector2::getX()
{
    return x;
}

double Vector2::getY()
{
    return y;
}

void Vector2::setX(double _x)
{
    x = _x;
}

void Vector2::setY(double _y)
{
    y = _y;
}