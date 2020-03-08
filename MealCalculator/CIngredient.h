#include <string>

#pragma once

/* Represents a Meal Ingredient */
class CIngredient
{
public:
	CIngredient(
		std::string name, 
		float grams, 
		float calories, 
		float fat,
		float carbohydrates,
		float protein
	);
	~CIngredient();

public:
	std::string getName();
	float getGrams();
	float getCaloriesPer100g();
	float getFatPer100g();
	float getCarbohydratesPer100g();
	float getProteinPer100g();

	float getTotalCalories();
	float getTotalFat();
	float getTotalCarbohydrates();
	float getTotalProtein();

	void setGrams(float grams);
	void setCaloriesPer100g(float calories);
	void setFatPer100g(float fat);
	void setCarbohydratesPer100g(float carbohydrates);
	void setProteinPer100g(float protein);

private:
	std::string name;
	float grams;
	float caloriesPer100g;
	float fatPer100g;
	float carbohydratesPer100g;
	float proteinPer100g;
};

