#include "CMeal.h"


// Constructor
CMeal::CMeal()
{
}


// Destructor
CMeal::~CMeal()
{
}

/* Adds an ingredient to the meal */
void CMeal::addIngredient(CIngredient& ingredient)
{
	ingredients.push_back(ingredient);
}

/* Checks if the Mea has an ingredient called <name> */
bool CMeal::hasIngredient(std::string ingredientName)
{
	for (CIngredient& ingredient : ingredients)
	{
		if (ingredient.getName() == ingredientName)
			return true;
	}

	return false;
}

/* Removes the specified ingredient from the Meal*/
void CMeal::removeIngredient(std::string ingredientName)
{
	size_t ingredientCount = getIngredientCount();
	int position = -1;
	for (int i = 0; i < ingredientCount; i++)
	{
		if (ingredients[i].getName() == ingredientName)
		{
			position = i;
			break;
		}
	}

	if (position == -1)
		return;

	ingredients.erase(ingredients.begin() + position);
}

/* Gets the Meal ingredient specified */
CIngredient* CMeal::getIngredient(std::string ingredientName)
{
	for (CIngredient& ingredient : ingredients)
	{
		if (ingredient.getName() == ingredientName)
		{
			return &ingredient;
		}
	}

	return nullptr;
}

/* Gets the count of Meal Ingredients */
size_t CMeal::getIngredientCount()
{
	return ingredients.size();
}


