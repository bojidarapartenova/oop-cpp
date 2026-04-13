#include "Product.h"
#include <compare>

Product::Product(std::string name_, std::string category_, double price_, int quantity_) : name(name_), category(category_), price(price_), quantity(quantity_) {}

const std::string &Product::getName() const
{
    return this->name;
}

const std::string &Product::getCategory() const
{
    return this->category;
}

double Product::getPrice() const
{
    return this->price;
}

int Product::getQuantity() const
{
    return this->quantity;
}

double Product::totalValue() const
{
    return this->price * this->quantity;
}

bool Product::operator==(const Product &other) const
{
    return (name == other.name) && (category == other.category) && (price == other.price) && (quantity == other.quantity);
}

std::ostream &operator<<(std::ostream &os, const Product &p)
{
    os << "Name: " << p.getName() << " Category: " << p.getCategory() << " Price: " << p.getPrice() << " Quantity: " << p.getQuantity();

    return os;
}