#include "Inventory.h"
#include <algorithm>
#include <print>
#include <iostream>

void Inventory::addProduct(const Product &p)
{
    this->products.push_back(p);
}

void Inventory::removeByName(const std::string &name)
{
    std::erase_if(this->products, [&](const Product &p)
                  { return p.getName() == name; });
}

std::vector<Product> Inventory::filterByCategory(const std::string &category) const
{
    std::vector<Product> result;
    for (const auto &p : products)
    {
        if (p.getCategory() == category)
        {
            result.push_back(p);
        }
    }
    return result;
}

std::vector<Product> Inventory::filterByPrice(double min, double max) const
{
    std::vector<Product> result;
    for (const auto &p : products)
    {
        if (p.getPrice() >= min && p.getPrice() <= max)
        {
            result.push_back(p);
        }
    }
    return result;
}

double Inventory::totalInventoryValue() const
{
    double result = 0;
    for (const auto &p : products)
    {
        result += (p.getPrice() * p.getQuantity());
    }
    return result;
}

void Inventory::sortByPrice()
{
    std::sort(products.begin(), products.end(), [](const Product &a, const Product &b)
              { return a.getPrice() < b.getPrice(); });
}

std::optional<Product> Inventory::findCheapest() const
{
    if (products.empty())
    {
        return std::nullopt;
    }

    return *std::min_element(products.begin(), products.end(), [](const Product &a, const Product &b)
                             { return a.getPrice() < b.getPrice(); });
}

void Inventory::print() const
{
    std::print("Products:\n");
    for (const auto &p : products)
    {
        std::print("Name: {}, Category: {}, Price: {}, Quantity: {}\n", p.getName(), p.getCategory(), p.getPrice(), p.getQuantity());
    }
}

Inventory::operator bool() const
{
    return !products.empty();
}
