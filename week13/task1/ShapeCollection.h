#ifndef SHAPECOLLECTION_H
#define SHAPECOLLECTION_H

#include <vector>
#include <memory>
#include "Shape.h"

class ShapeCollection
{
private:
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    void add(std::unique_ptr<Shape> shape);
    double getTotalArea() const;
    double getTotalPerimeter() const;
    const Shape *getLargestByArea() const;
    const Shape *getSmallestByArea() const;
    void printAll(std::ostream &os) const;
    std::vector<const Shape *> filterByMinArea(double minArea) const;
};

#endif