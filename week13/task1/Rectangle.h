#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
    double width;
    double height;

public:
    Rectangle(double width, double height);

    double getArea() const override;
    double getPerimeter() const override;
    std::string getName() const override;
};

#endif