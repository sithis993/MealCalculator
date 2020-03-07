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

/* Gets the count of Meal Ingredients */
size_t CMeal::getIngredientCount()
{
	return ingredients.size();
}


