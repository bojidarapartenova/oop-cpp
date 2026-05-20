#include "Circle.h"
#include <cmath>

Circle::Circle(double radius) : radius(radius)
{
    if (radius <= 0)
    {
        throw new std::invalid_argument("radius must be more than 0");
    }
}

double Circle::getArea() const
{
    return M_PI * radius * radius;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * radius;
}

std::string Circle::getName() const
{
    return "circle";
}
