#include <vector>
#include <fstream>
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
	void removeAllIngredients();
	CIngredient* getIngredient(std::string ingredientName);
	std::vector<CIngredient>* getIngredients();

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

	void saveToFile(std::string path);
	void loadFromFile(std::string path);

private:
	std::vector<CIngredient> ingredients;
};

