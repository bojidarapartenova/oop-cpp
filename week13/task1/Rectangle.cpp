#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : width(width), height(height)
{
    if (width <= 0 || height <= 0)
    {
        throw new std::invalid_argument("width and height must be more than 0");
    }
}

double Rectangle::getArea() const
{
    return width * height;
}

double Rectangle::getPerimeter() const
{
    return 2 * (width + height);
}

std::string Rectangle::getName() const
{
    return "rectangle";
}
