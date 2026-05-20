#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c)
{
    if (a + b < c || a + c < b || b + c < a || a <= 0 || b <= 0 || c <= 0)
    {
        throw new std::invalid_argument("invalid sides");
    }
}

double Triangle::getArea() const
{
    double semiPer = (a + b + c) / 2;
    return sqrt(semiPer * (semiPer - a) * (semiPer - b) * (semiPer - c));
}

double Triangle::getPerimeter() const
{
    return a + b + c;
}

std::string Triangle::getName() const
{
    return "triangle";
}
