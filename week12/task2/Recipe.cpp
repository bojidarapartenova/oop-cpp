#include "Recipe.h"

Recipe::Recipe(const std::string name, int servings, int cookingTime) : name(name), servings(servings), cookingTimeMinutes(cookingTime) {}

std::expected<Recipe, RecipeError> Recipe::create(const std::string &name, int servings, int cookingTimeMinutes)
{
    if (name.empty())
    {
        return std::unexpected(RecipeError::EmptyName);
    }

    if (servings <= 0)
    {
        return std::unexpected(RecipeError::InvalidServings);
    }

    if (cookingTimeMinutes <= 0)
    {
        return std::unexpected(RecipeError::InvalidCookingTime);
    }

    return Recipe(name, servings, cookingTimeMinutes);
}

std::expected<void, RecipeError> Recipe::addIngredient(const Ingredient &ingredient)
{
    for (size_t i = 0; i < ingredients.size(); i++)
    {
        if (ingredients[i].getName() == ingredient.getName())
        {
            return std::unexpected(RecipeError::DuplicateIngredient);
        }
    }
    ingredients.push_back(ingredient);
}

std::expected<void, RecipeError> Recipe::removeIngredient(const std::string &name)
{
    int size = ingredients.size();
    std::erase_if(ingredients, [&name](const Ingredient i)
                  { return i.getName() == name; });

    int newSize = ingredients.size();

    if (size == newSize)
    {
        return std::unexpected(RecipeError::IngredientNotFound);
    }
}

std::optional<Ingredient> Recipe::findIngredient(const std::string &name) const
{
    if (name.empty())
    {
        return std::nullopt;
    }

    for (const auto &i : ingredients)
    {
        if (i.getName() == name)
        {
            return i;
        }
    }
    return std::nullopt;
}

std::expected<Recipe, RecipeError> Recipe::scaleToServings(int targetServings) const
{
    if (targetServings <= 0)
    {
        return std::unexpected(RecipeError::InvalidServings);
    }

    if (ingredients.empty())
    {
        return std::unexpected(RecipeError::EmptyRecipe);
    }

    return Recipe(name, targetServings, cookingTimeMinutes);
}

std::optional<int> Recipe::estimatedCaloriesPerServing() const
{
    if (ingredients.empty())
    {
        return std::nullopt;
    }

    return 100 * ingredients.size() * servings;
}

const std::string &Recipe::getName() const
{
    return name;
}

int Recipe::getServings() const
{
    return servings;
}

int Recipe::getCookingTimeMinutes() const
{
    return cookingTimeMinutes;
}

const std::vector<Ingredient> &Recipe::getIngredients() const
{
    return ingredients;
}
