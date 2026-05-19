#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include "Recipe.h"

class RecipeBook
{
private:
    std::string title;
    std::vector<Recipe> recipes;

public:
    RecipeBook(const std::string &title);

    std::expected<void, RecipeError> addRecipe(const Recipe &recipe);
    std::expected<void, RecipeError> removeRecipe(const std::string &name);
    std::optional<Recipe> findRecipe(const std::string &name) const;
    std::optional<Recipe> findQuickestRecipe() const;
    std::vector<Recipe> getRecipesUnder(int maxMinutes) const;
    int totalRecipes() const;
};

#endif