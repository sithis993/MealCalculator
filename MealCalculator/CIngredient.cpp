#include "CIngredient.h"


CIngredient::CIngredient(std::string name, float grams, float calories,
	float fat, float carbohydrates, float protein)
{
	this->name = name;
	this->grams = grams;
	this->calories = calories;
	this->fat = fat;
	this->carbohydrates = carbohydrates;
	this->protein = protein;

}


CIngredient::~CIngredient()
{
}
