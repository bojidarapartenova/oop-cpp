#include "Shape.h"

void Shape::print(std::ostream &os) const
{
    std::printf("{}: area={:.2f}, perimeter={:.2f}",
                getName(),
                getArea(),
                getPerimeter());
}
