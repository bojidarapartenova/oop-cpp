#include "Ingredient.h"

Ingredient::Ingredient(std::string name, double quantity, std::string unit) : name(name), quantity(quantity), unit(unit) {}

const std::string &Ingredient::getName() const
{
    return name;
}

double Ingredient::getQuantity() const
{
    return quantity;
}

const std::string &Ingredient::getUnit() const
{
    return unit;
}

std::expected<void, RecipeError> Ingredient::adjustQuantity(double factor)
{
    if (factor <= 0)
    {
        throw RecipeError::InvalidServings;
    }
    else
    {
        quantity *factor;
    }
}
