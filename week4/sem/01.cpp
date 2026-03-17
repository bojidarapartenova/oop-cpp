#include <iostream>
#include <fstream>
#include <cmath>
#include <print>

enum class Quadrant
{
    I,
    II,
    III,
    IV,
    None
};

class Point
{
private:
    int x = 0;
    int y = 0;

    mutable int counter = 0;

public:
    Point() = default;
    Point(int x_, int y_) : x(x_), y(y_) {}

    int GetX() const
    {
        counter++;
        return x;
    }
    int GetY() const
    {
        counter++;
        return y;
    }

    void SetX(int x_)
    {
        counter++;
        x = x_;
    }
    void SetY(int y_)
    {
        counter++;
        y = y_;
    }

    double CalcDistance(const Point &other) const
    {
        counter++;
        double distance = sqrt((pow((other.x - this->x), 2)) + (pow((other.y - this->y), 2)));
        return distance;
    }

    Quadrant CalcQuadrant() const
    {
        counter++;
        if (this->x == 0 || this->y == 0)
        {
            return Quadrant::None;
        }

        if (this->x > 0 && this->y > 0)
        {
            return Quadrant::I;
        }

        if (this->x < 0 && this->y > 0)
        {
            return Quadrant::II;
        }

        if (this->x < 0 && this->y < 0)
        {
            return Quadrant::III;
        }

        if (this->x > 0 && this->y < 0)
        {
            return Quadrant::IV;
        }

        return Quadrant::None;
    }

    void WriteFile(const char *fileName) const
    {
        counter++;
        std::ofstream file(fileName);
        if (!file.is_open())
        {
            return;
        }

        file << x << ' ' << y << ' ';
        file.close();
    }

    void WriteStream(std::ostream &os) const
    {
        counter++;
        os << x << ' ' << y << ' ';
    }

    void ReadFile(const char *fileName)
    {
        counter++;
        std::ifstream file(fileName);
        if (!file.is_open())
        {
            return;
        }

        file >> x >> y;
    }

    void ReadStream(std::istream &is)
    {
        counter++;
        is >> x >> y;
    }

    int GetCounter() const
    {
        return counter;
    }

    void ResetCounter()
    {
        counter = 0;
    }

    void PointInfo()
    {
        std::cout << x << y << std::endl;
    }

    ~Point()
    {
        std::printf("point destroyed. \n");
    }
};

class Triangle
{
private:
    // Point a;
    // Point b;
    // Point c;

    Point points[3];

    mutable int counter = 0;

public:
    Triangle() = default;

    Triangle(Point points_[3])
    {
        for (size_t i = 0; i < 3; i++)
        {
            this->points[i] = points_[i];
        }
    }
    Point GetA() const
    {
        counter++;
        return points[0];
    }
    Point GetB() const
    {
        counter++;
        return points[1];
    }
    Point GetC() const
    {
        counter++;
        return points[2];
    }

    void SetA(const Point a_)
    {
        counter++;
        points[0] = a_;
    }
    void SetB(const Point b_)
    {
        counter++;
        points[1] = b_;
    }
    void SetC(const Point c_)
    {
        counter++;
        points[2] = c_;
    }

    double CalcPerimeter() const
    {
        counter++;
        return points[0].CalcDistance(points[1]) + points[1].CalcDistance(points[2]) + points[0].CalcDistance(points[2]);
    }

    double CalcArea() const
    {
        counter++;
        double semiPer = CalcPerimeter() / 2;
        return sqrt(semiPer * (semiPer - points[0].CalcDistance(points[1])) * (semiPer - points[1].CalcDistance(points[2])) * (semiPer - points[0].CalcDistance(points[2])));
    }

    Quadrant CalcQuadrant() const
    {
        counter++;
        Point point;
        double gx = (points[0].GetX() + points[1].GetX() + points[2].GetX()) / 3.0;
        double gy = (points[0].GetY() + points[1].GetY() + points[2].GetY()) / 3.0;

        point.SetX(gx);
        point.SetY(gy);

        return point.CalcQuadrant();
    }

    void WriteFile(const char *fileName) const
    {
        counter++;
        std::ofstream file(fileName);
        if (!file)
        {
            return;
        }
        points[0].WriteStream(file);
        points[1].WriteStream(file);
        points[2].WriteStream(file);
    }

    void ReadFile(const char *fileName)
    {
        counter++;
        std::ifstream file(fileName);
        if (!file)
        {
            return;
        }
        points[0].ReadStream(file);
        points[1].ReadStream(file);
        points[2].ReadStream(file);
    }

    void WriteStream(std::ostream &os) const
    {
        counter++;
        points[0].WriteStream(os);
        points[1].WriteStream(os);
        points[2].WriteStream(os);
    }

    void ReadStream(std::istream &is)
    {
        counter++;
        points[0].ReadStream(is);
        points[1].ReadStream(is);
        points[2].ReadStream(is);
    }

    void ResetCounter()
    {
        counter = 0;
    }

    int GetCounter() const
    {
        return counter;
    }

    ~Triangle()
    {
        std::printf("triangle destroyed. \n");
    }
};

int main()
{
    std::cout << "Enter coordinates for point A (x y): ";
    double xA, yA;
    std::cin >> xA >> yA;
    Point a(xA, yA);

    // Point a;
    // a.SetX(xA);
    // a.SetY(yA);
    // t.SetA(a);

    std::cout << "Enter coordinates for point B (x y): ";
    double xB, yB;
    std::cin >> xB >> yB;
    Point b(xB, yB);

    // Point b;
    // b.SetX(xB);
    // b.SetY(yB);
    // t.SetB(b);

    std::cout << "Enter coordinates for point C (x y): ";
    double xC, yC;
    std::cin >> xC >> yC;
    Point c(xC, yC);

    // Point c;
    // c.SetX(xC);
    // c.SetY(yC);
    // t.SetC(c);

    Point points[] = {a, b, c};

    Triangle t(points);
    std::cout
        << "Perimeter: " << t.CalcPerimeter() << std::endl;
    std::cout << "Area: " << t.CalcArea() << std::endl;

    Quadrant quad = t.CalcQuadrant();
    std::cout << "Centroid quadrant: ";
    switch (quad)
    {
    case Quadrant::I:
        std::cout << "I";
        break;
    case Quadrant::II:
        std::cout << "II";
        break;
    case Quadrant::III:
        std::cout << "III";
        break;
    case Quadrant::IV:
        std::cout << "IV";
        break;
    case Quadrant::None:
        std::cout << "None";
        break;
    }
    std::cout << std::endl;

    std::cout << "Triangle usage counter: " << t.GetCounter() << std::endl;
}