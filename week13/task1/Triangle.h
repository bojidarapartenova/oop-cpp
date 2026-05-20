#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
private:
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c);

    double getArea() const override;
    double getPerimeter() const override;
    std::string getName() const override;
};

#endif