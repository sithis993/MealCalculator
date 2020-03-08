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

std::string CIngredient::getName()
{
	return name;
}

float CIngredient::getGrams()
{
	return grams;
}

float CIngredient::getCalories()
{
	return calories;
}

float CIngredient::getFat()
{
	return fat;
}

float CIngredient::getCarbohydrates()
{
	return carbohydrates;
}

float CIngredient::getProtein()
{
	return protein;
}

void CIngredient::setGrams(float grams)
{
	this->grams = grams;
}

void CIngredient::setCalories(float calories)
{
	this->calories = calories;
}

void CIngredient::setFat(float fat)
{
	this->fat = fat;
}

void CIngredient::setCarbohydrates(float carbohydrates)
{
	this->carbohydrates = carbohydrates;
}

void CIngredient::setProtein(float protein)
{
	this->protein = protein;
}
