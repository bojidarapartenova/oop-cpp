#include "01.h"
#include <iostream>

BigNumber::BigNumber() : digits(nullptr), size(0) {}

BigNumber::BigNumber(const BigNumber &other)
{
    copyNum(other);
}

BigNumber &BigNumber::operator=(const BigNumber &other)
{
    if (this != &other)
    {
        delete[] digits;
        copyNum(other);
    }
    return *this;
}

BigNumber::BigNumber(BigNumber &&other) noexcept : digits(other.digits), size(other.size)
{
    other.digits = nullptr;
    other.size = 0;
}

BigNumber &BigNumber::operator=(BigNumber &&other) noexcept
{
    if (this != &other)
    {
        delete[] digits;

        digits = other.digits;
        size = other.size;

        other.digits = nullptr;
        other.size = 0;
    }
    return *this;
}

BigNumber::~BigNumber()
{
    delete[] digits;
}

size_t BigNumber::length() const
{
    return this->size;
}

bool BigNumber::isZero() const
{
    return (size == 0 && digits[0] == '0');
}
void BigNumber::removeLeadingZeros()
{
    int i = 0;
    while (i < size - 1 && digits[i] == '0')
    {
        i++;
    }

    if (i == 0)
    {
        return;
    }

    size_t newSize = size - i;
    char *newDigits = new char[newSize];
    for (size_t j = i; j < newSize; j++)
    {
        newDigits[i] = digits[i + j];
    }

    delete[] digits;
    digits = newDigits;
    size = newSize;
}
