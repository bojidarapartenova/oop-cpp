#include "01.h"
#include <iostream>

MovieCD::MovieCD() : title(nullptr), rentalPrice(0.0), availableCopies(0) {}

MovieCD::MovieCD(const char *title, double rentalPrice, int availableCopies) : rentalPrice(rentalPrice), availableCopies(availableCopies)
{
    copyTitle(title);
}

MovieCD::MovieCD(const MovieCD &other) : rentalPrice(other.rentalPrice), availableCopies(other.availableCopies)
{
    copyTitle(other.title);
}

MovieCD &MovieCD::operator=(const MovieCD &other)
{
    if (this != &other)
    {
        delete[] title;

        copyTitle(other.title);
        rentalPrice = other.rentalPrice;
        availableCopies = other.availableCopies;
    }
    return *this;
}

MovieCD::MovieCD(MovieCD &&other) noexcept : title(other.title), rentalPrice(other.rentalPrice), availableCopies(other.availableCopies)
{
    other.title = nullptr;
    other.rentalPrice = 0.0;
    other.availableCopies = 0;
}

MovieCD &MovieCD::operator=(MovieCD &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] title;

    title = other.title;
    rentalPrice = other.rentalPrice;
    availableCopies = other.availableCopies;

    other.title = nullptr;
    other.rentalPrice = 0.0;
    other.availableCopies = 0;

    return *this;
}

MovieCD::~MovieCD()
{
    delete[] title;
}

double MovieCD::getTotalRentalValue() const
{
    return rentalPrice * availableCopies;
}

bool MovieCD::isAvailable() const
{
    if (availableCopies > 0)
    {
        return true;
    }
    return false;
}

void MovieCD::print() const
{
    std::cout << "Title: " << (title ? title : "N/A") << "\n"
              << "Rental price: " << rentalPrice << "\n"
              << "Available copies: " << availableCopies << "\n"
              << "Total value: " << getTotalRentalValue() << "\n";
}

int main()
{
}