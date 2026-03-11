#include <iostream>
#include <fstream>
#include <cmath>

enum Quadrant
{
    I = 1,
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

        file << x << ' ' << y;
        file.close();
    }

    void WriteStream(std::ostream &os) const
    {
        counter++;
        os << x << " " << y;
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
};

class Triangle
{
private:
    Point a;
    Point b;
    Point c;

    mutable int counter = 0;

public:
    Point GetA() const
    {
        counter++;
        return a;
    }
    Point GetB() const
    {
        counter++;
        return b;
    }
    Point GetC() const
    {
        counter++;
        return c;
    }

    void SetA(const Point &a_)
    {
        counter++;
        a = a_;
    }
    void SetB(const Point &b_)
    {
        counter++;
        b = b_;
    }
    void SetC(const Point &c_)
    {
        counter++;
        c = c_;
    }

    double CalcPerimeter() const
    {
        counter++;
        return a.CalcDistance(b) + b.CalcDistance(c) + a.CalcDistance(c);
    }

    double CalcArea() const
    {
        counter++;
        double semiPer = CalcPerimeter() / 2;
        return sqrt(semiPer * (semiPer - a.CalcDistance(b)) * (semiPer - b.CalcDistance(c)) * (semiPer - a.CalcDistance(c)));
    }

    Quadrant CalcQuadrant() const
    {
        counter++;
        Point point;
        double gx = (a.GetX() + b.GetX() + c.GetX()) / 3.0;
        double gy = (a.GetY() + b.GetY() + c.GetY()) / 3.0;

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
        a.WriteStream(file);
        b.WriteStream(file);
        c.WriteStream(file);
    }

    void ReadFile(const char *fileName)
    {
        counter++;
        std::ifstream file(fileName);
        if (!file)
        {
            return;
        }
        a.ReadStream(file);
        b.ReadStream(file);
        c.ReadStream(file);
    }

    void WriteStream(std::ostream &os) const
    {
        counter++;
        a.WriteStream(os);
        b.WriteStream(os);
        c.WriteStream(os);
    }

    void ReadStream(std::istream &is)
    {
        counter++;
        a.ReadStream(is);
        b.ReadStream(is);
        c.ReadStream(is);
    }

    void ResetCounter()
    {
        counter = 0;
    }

    int GetCounter() const
    {
        return counter;
    }
};

int main()
{
    Triangle t;

    std::cout << "Enter coordinates for point A (x y): ";
    double xA, yA;
    std::cin >> xA >> yA;
    Point a;
    a.SetX(xA);
    a.SetY(yA);
    t.SetA(a);

    std::cout << "Enter coordinates for point B (x y): ";
    double xB, yB;
    std::cin >> xB >> yB;
    Point b;
    b.SetX(xB);
    b.SetY(yB);
    t.SetB(b);

    std::cout << "Enter coordinates for point C (x y): ";
    double xC, yC;
    std::cin >> xC >> yC;
    Point c;
    c.SetX(xC);
    c.SetY(yC);
    t.SetC(c);

    std::cout << "Perimeter: " << t.CalcPerimeter() << std::endl;
    std::cout << "Area: " << t.CalcArea() << std::endl;

    Quadrant quad = t.CalcQuadrant();
    std::cout << "Centroid quadrant: ";
    switch (quad)
    {
    case I:
        std::cout << "I";
        break;
    case II:
        std::cout << "II";
        break;
    case III:
        std::cout << "III";
        break;
    case IV:
        std::cout << "IV";
        break;
    case None:
        std::cout << "None";
        break;
    }
    std::cout << std::endl;

    std::cout << "Triangle usage counter: " << t.GetCounter() << std::endl;
}