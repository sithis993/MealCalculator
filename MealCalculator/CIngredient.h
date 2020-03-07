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

private:
	std::string name;
	float grams;
	float calories;
	float fat;
	float carbohydrates;
	float protein;
};

