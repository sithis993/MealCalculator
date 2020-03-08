#include <vector>
#include "CIngredient.h"

#pragma once

// Represents a Meal
class CMeal
{
public:
	CMeal();
	~CMeal();

public:
	void addIngredient(CIngredient& ingredient);
	bool hasIngredient(std::string ingredientName);
	void removeIngredient(std::string ingredientName);
	CIngredient* getIngredient(std::string ingredientName);

	size_t getIngredientCount();
	float getTotalWeightGrams();
	float getTotalCalories();
	float getTotalFat();
	float getTotalCarbohydrates();
	float getTotalProtein();

	float getCaloriesPer100g();
	float getFatPer100g();
	float getCarbohydratesPer100g();
	float getProteinPer100g();
	// TODO implement per 100g methods for carbs and protein

private:
	std::vector<CIngredient> ingredients;
};

