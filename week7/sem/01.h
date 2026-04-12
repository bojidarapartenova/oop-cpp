#include <fstream>

class Imaginary
{
private:
    double real;

public:
    Imaginary(double value = 1);
    Imaginary(double real_);

    int getValue() const;
    void setValue(double value);

    Imaginary &operator+=(const Imaginary &other);
    Imaginary &operator-=(const Imaginary &other);
    Imaginary &operator*=(double value);
    Imaginary &operator/=(double value);

    friend std::ostream &operator<<(std::ostream &os, const Imaginary &im);
    friend std::istream &operator>>(std::istream &is, const Imaginary &im);

    Imaginary &operator+(const Imaginary &other);
    Imaginary &operator-(const Imaginary &other);
};