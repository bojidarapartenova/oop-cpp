#ifndef RECIPE_H
#define RECIPE_H

#include "Ingredient.h"
#include <vector>
#include <string>
#include <optional>

class Recipe
{
private:
    std::string name;
    int servings;
    int cookingTimeMinutes;
    std::vector<Ingredient> ingredients;

public:
    Recipe(const std::string name, int servings, int cookingTime);

    static std::expected<Recipe, RecipeError> create(const std::string &name, int servings, int cookingTimeMinutes);
    std::expected<void, RecipeError> addIngredient(const Ingredient &ingredient);
    std::expected<void, RecipeError> removeIngredient(const std::string &name);
    std::optional<Ingredient> findIngredient(const std::string &name) const;
    std::expected<Recipe, RecipeError> scaleToServings(int targetServings) const;
    std::optional<int> estimatedCaloriesPerServing() const;

    const std::string &getName() const;
    int getServings() const;
    int getCookingTimeMinutes() const;
    const std::vector<Ingredient> &getIngredients() const;
};

#endif