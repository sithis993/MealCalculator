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
	for (unsigned int i = 0; i < ingredientCount; i++)
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

void CMeal::removeAllIngredients()
{
	ingredients.clear();

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

/* Gets the total Meal weight in grams */
float CMeal::getTotalWeightGrams()
{
	float totalGrams = 0;

	for (CIngredient& ingredient : ingredients)
	{
		totalGrams += ingredient.getGrams();
	}

	return totalGrams;
}

/* Gets the total number of calories in the meal */
float CMeal::getTotalCalories()
{
	float totalCals = 0;

	for (CIngredient& ingredient : ingredients)
	{
		totalCals += ingredient.getTotalCalories();
	}

	return totalCals;
}

/* Gets the total amount of fat in the meal */
float CMeal::getTotalFat()
{
	float totalFat = 0;

	for (CIngredient& ingredient : ingredients)
	{
		totalFat += ingredient.getTotalFat();
	}

	return totalFat;
}

float CMeal::getTotalCarbohydrates()
{
	float totalCarbohydrates = 0;

	for (CIngredient& ingredient : ingredients)
	{
		totalCarbohydrates += ingredient.getTotalCarbohydrates();
	}

	return totalCarbohydrates;
}

float CMeal::getTotalProtein()
{
	float totalProtein = 0;

	for (CIngredient& ingredient : ingredients)
	{
		totalProtein += ingredient.getTotalProtein();
	}

	return totalProtein;
}


/* Gets the number calories per 100g */
float CMeal::getCaloriesPer100g()
{
	float cals = 0;
	float totalGrams = getTotalWeightGrams();

	if (totalGrams > 0)
	{
		cals = getTotalCalories() * (100 / totalGrams);
	}

	return cals;
}

float CMeal::getFatPer100g()
{
	float fat = 0;
	float totalGrams = getTotalWeightGrams();

	if (totalGrams > 0)
	{
		fat = getTotalFat() * (100 / totalGrams);
	}

	return fat;
}

float CMeal::getCarbohydratesPer100g()
{
	float carbohydrates = 0;
	float totalGrams = getTotalWeightGrams();

	if (totalGrams > 0)
	{
		carbohydrates = getTotalCarbohydrates() * (100 / totalGrams);
	}

	return carbohydrates;
}

float CMeal::getProteinPer100g()
{
	float protein = 0;
	float totalGrams = getTotalWeightGrams();

	if (totalGrams > 0)
	{
		protein = getTotalProtein() * (100 / totalGrams);
	}

	return protein;
}


