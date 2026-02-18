#include <iostream>

struct Point
{
    int x;
    int y;

    void read()
    {
        std::cin >> x >> y;
    }

    void print()
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    double distanceFromOrigin() const
    {
        return std::sqrt(x * x + y * y);
    }

    double distanceTo(const Point &other) const
    {
        double dx = this->x - other.x;
        double dy = this->y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    std::string quadrant() const
    {
        if (x > 0 && y > 0)
            return "Quadrant I";
        if (x < 0 && y > 0)
            return "Quadrant II";
        if (x < 0 && y < 0)
            return "Quadrant III";
        if (x > 0 && y < 0)
            return "Quadrant IV";
        if (x == 0 && y != 0)
            return "On Y axis";
        if (y == 0 && x != 0)
            return "On X axis";
        return "Origin";
    }

    bool isInCircle(double r) const
    {
        return distanceFromOrigin() <= r;
    }
};

int main()
{
    Point p1, p2;

    std::cout << "Enter point P1 (x y): ";
    p1.read();

    std::cout << "Enter point P2 (x y): ";
    p2.read();

    std::cout << "Point P1: ";
    p1.print();
    std::cout << "Point P2: ";
    p2.print();

    std::cout << "Distance of P1 from origin: " << p1.distanceFromOrigin() << std::endl;
    std::cout << "Distance between P1 and P2: " << p1.distanceTo(p2) << std::endl;

    std::cout << "P1 is in: " << p1.quadrant() << std::endl;
    std::cout << "P2 is in: " << p2.quadrant() << std::endl;

    double r;
    std::cout << "Enter radius of circle centered at origin: ";
    std::cin >> r;

    if (p1.isInCircle(r))
    {
        std::cout << "P1 is inside or on the circle.";
    }
    else
    {
        std::cout << "P1 is outside the circle.";
    }
    std::cout << std::endl;
    if (p2.isInCircle(r))
    {
        std::cout << "P2 is inside or on the circle.";
    }
    else
    {
        std::cout << "P2 is outside the circle.";
    }
}