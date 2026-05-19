#include "RecipeBook.h"

RecipeBook::RecipeBook(const std::string &title) : title(title) {}

std::expected<void, RecipeError> RecipeBook::addRecipe(const Recipe &recipe)
{
    for (size_t i = 0; i < recipes.size(); i++)
    {
        if (recipes[i].getName() == recipe.getName())
        {
            return std::unexpected(RecipeError::DuplicateIngredient);
        }
    }
    recipes.push_back(recipe);
}

std::expected<void, RecipeError> RecipeBook::removeRecipe(const std::string &name)
{
    int size = recipes.size();
    std::erase_if(recipes, [&name](const Recipe r)
                  { return r.getName() == name; });

    int newSize = recipes.size();

    if (size == newSize)
    {
        return std::unexpected(RecipeError::IngredientNotFound);
    }
}

std::optional<Recipe> RecipeBook::findRecipe(const std::string &name) const
{
    if (name.empty())
    {
        return std::nullopt;
    }

    for (const auto &r : recipes)
    {
        if (r.getName() == name)
        {
            return r;
        }
    }
    return std::nullopt;
}

std::optional<Recipe> RecipeBook::findQuickestRecipe() const
{
    if (recipes.empty())
    {
        return std::nullopt;
    }

    const Recipe *quickest = &recipes[0];
    for (const auto &r : recipes)
    {
        if (r.getCookingTimeMinutes() < quickest->getCookingTimeMinutes())
        {
            quickest = &r;
        }
    }
    return *quickest;
}

std::vector<Recipe> RecipeBook::getRecipesUnder(int maxMinutes) const
{
    std::vector<Recipe> result;
    for (const auto &r : recipes)
    {
        if (r.getCookingTimeMinutes() <= maxMinutes)
        {
            result.push_back(r);
        }
    }
    return result;
}

int RecipeBook::totalRecipes() const
{
    return recipes.size();
}
