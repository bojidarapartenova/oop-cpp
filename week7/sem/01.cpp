#include <iostream>
#include <fstream>
#include "01.h"

Imaginary::Imaginary(double value) : real(value) {}
Imaginary::Imaginary(double real_) : real(real_) {}

int Imaginary::getValue() const
{
    return this->real;
}

void Imaginary::setValue(double value)
{
    this->real = value;
}

Imaginary &Imaginary::operator+=(const Imaginary &other)
{
    this->real += other.real;
    return *this;
}

Imaginary &Imaginary::operator-=(const Imaginary &other)
{
    this->real -= other.real;
    return *this;
}

Imaginary &Imaginary::operator*=(double value)
{
    this->real *= value;
    return *this;
}

Imaginary &Imaginary::operator/=(double value)
{
    this->real /= value;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Imaginary &im)
{
    return os << im.real << 'i';
}

std::istream &operator>>(std::istream &is, const Imaginary &im)
{
    return is >> im.real >> 'i';
}

Imaginary &Imaginary::operator+(const Imaginary &other)
{
    double result = this->real + other.real;
    Imaginary im(result);
    im.setValue(result);
    return im;
}

Imaginary &Imaginary::operator-(const Imaginary &other)
{
    double result = this->real - other.real;
    Imaginary im;
    im.setValue(result);
    return im;
}

int main()
{
}