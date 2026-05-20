#include "ShapeCollection.h"

void ShapeCollection::add(std::unique_ptr<Shape> shape)
{
    shapes.push_back(shape);
}

double ShapeCollection::getTotalArea() const
{
    double sum = 0;
    for (const auto &s : shapes)
    {
        sum += s->getArea();
    }
    return sum;
}

double ShapeCollection::getTotalPerimeter() const
{
    double sum = 0;
    for (const auto &s : shapes)
    {
        sum += s->getPerimeter();
    }
    return sum;
}

const Shape *ShapeCollection::getLargestByArea() const
{
    if (shapes.empty())
    {
        return nullptr;
    }

    const Shape *largest = shapes[0].get();
    for (const auto &s : shapes)
    {
        if (s->getArea() > largest->getArea())
        {
            largest = s.get();
        }
    }
    return largest;
}

const Shape *ShapeCollection::getSmallestByArea() const
{
    if (shapes.empty())
    {
        return nullptr;
    }

    const Shape *smallest = shapes[0].get();
    for (const auto &s : shapes)
    {
        if (s->getArea() < smallest->getArea())
        {
            smallest = s.get();
        }
    }
    return smallest;
}

void ShapeCollection::printAll(std::ostream &os) const
{
    for (const auto &s : shapes)
    {
        s->print(os);
    }
}

std::vector<const Shape *> ShapeCollection::filterByMinArea(double minArea) const
{
    std::vector<const Shape *> result;
    for (const auto &s : shapes)
    {
        if (s->getArea() >= minArea)
        {
            result.push_back(s.get());
        }
    }
    return result;
}
