#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "RecipeError.h"
#include <string>
#include <expected>

class Ingredient
{
private:
    std::string name;
    double quantity;
    std::string unit;

public:
    Ingredient(std::string name, double quantity, std::string unit);

    const std::string &getName() const;
    double getQuantity() const;
    const std::string &getUnit() const;
    std::expected<void, RecipeError> adjustQuantity(double factor);
};

#endif