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
	float getCalories();
	float getFat();
	float getCarbohydrates();
	float getProtein();

	void setGrams(float grams);
	void setCalories(float calories);
	void setFat(float fat);
	void setCarbohydrates(float carbohydrates);
	void setProtein(float protein);

private:
	std::string name;
	float grams;
	float calories;
	float fat;
	float carbohydrates;
	float protein;
};

