#include "CIngredient.h"

CIngredient::CIngredient(std::string name, float grams, float calories,
	float fat, float carbohydrates, float protein)
{
	this->name = name;
	this->grams = grams;
	this->caloriesPer100g = calories;
	this->fatPer100g = fat;
	this->carbohydratesPer100g = carbohydrates;
	this->proteinPer100g = protein;
}

CIngredient::~CIngredient()
{
}

/* Gets the ingredient's name */
std::string CIngredient::getName()
{
	return name;
}

std::string CIngredient::getGramsString()
{
	char stringBuffer[10];
	sprintf(stringBuffer, "%.2f", getGrams());

	return std::string(stringBuffer);
}

std::string CIngredient::getCaloriesPer100gString()
{
	char stringBuffer[10];
	sprintf(stringBuffer, "%.2f", getCaloriesPer100g());

	return std::string(stringBuffer);
}

std::string CIngredient::getFatPer100gString()
{
	char stringBuffer[10];
	sprintf(stringBuffer, "%.2f", getFatPer100g());

	return std::string(stringBuffer);
}

std::string CIngredient::getCarbohydratesPer100gString()
{
	char stringBuffer[10];
	sprintf(stringBuffer, "%.2f", getCarbohydratesPer100g());

	return std::string(stringBuffer);
}

std::string CIngredient::getProteinPer100gString()
{
	char stringBuffer[10];
	sprintf(stringBuffer, "%.2f", getProteinPer100g());

	return std::string(stringBuffer);
}

/* Gets the amount of ingredient grams */
float CIngredient::getGrams()
{
	return grams;
}

/* Gets the number of ingredient calories per 100g */
float CIngredient::getCaloriesPer100g()
{
	return caloriesPer100g;
}

/* Gets the amount of fat in grams per 100g of ingredient */
float CIngredient::getFatPer100g()
{
	return fatPer100g;
}

/* Gets the amount of carbohydrates in grams per 100g of ingredient */
float CIngredient::getCarbohydratesPer100g()
{
	return carbohydratesPer100g;
}

/* Gets the amount of protein in grams per 100g of ingredient */
float CIngredient::getProteinPer100g()
{
	return proteinPer100g;
}

/* Gets the total amount of calories */
float CIngredient::getTotalCalories()
{
	return getCaloriesPer100g() * (getGrams() / 100);
}

/* Gets the total amount of fat */
float CIngredient::getTotalFat()
{
	return getFatPer100g() * (getGrams() / 100);
}

/* Gets the total amount of carbohydrates */
float CIngredient::getTotalCarbohydrates()
{
	return getCarbohydratesPer100g() * (getGrams() / 100);
}

/* Gets the total amount of protein */
float CIngredient::getTotalProtein()
{
	return getProteinPer100g() * (getGrams() / 100);
}

/* Sets the amount of ingredient grams */
void CIngredient::setGrams(float grams)
{
	this->grams = grams;
}

/* Sets the number of calories per 100 grams of ingredient */
void CIngredient::setCaloriesPer100g(float calories)
{
	this->caloriesPer100g = calories;
}

/* Sets the amount of fat in grams per 100 grams of ingredient */
void CIngredient::setFatPer100g(float fat)
{
	this->fatPer100g = fat;
}

/* Sets the amount of carbohydrates in grams per 100 grams of ingredient */
void CIngredient::setCarbohydratesPer100g(float carbohydrates)
{
	this->carbohydratesPer100g = carbohydrates;
}

/* Sets the amount of protein in grams per 100 grams of ingredient */
void CIngredient::setProteinPer100g(float protein)
{
	this->proteinPer100g = protein;
}

/* Saves the ingredient data to a file */
void CIngredient::saveToFile(std::string path)
{
	std::ofstream out(path);

	out << name << "\n";
	out << caloriesPer100g << "\n" ;
	out << fatPer100g << "\n" ;
	out << carbohydratesPer100g << "\n" ;
	out << proteinPer100g << "\n";

	out.close();
	
}

CIngredient* CIngredient::loadFromFile(std::string path)
{
	std::ifstream in(path);

	std::string name;
	std::string caloriesPer100g;
	std::string fatPer100g;
	std::string carbohydratesPer100g;
	std::string proteinPer100g;

	std::getline(in, name);
	std::getline(in, caloriesPer100g);
	std::getline(in, fatPer100g);
	std::getline(in, carbohydratesPer100g);
	std::getline(in, proteinPer100g);

	CIngredient* ingredient = new CIngredient(
		name, 0.0, 
		std::stof(caloriesPer100g), std::stof(fatPer100g), 
		std::stof(carbohydratesPer100g), std::stof(proteinPer100g)
	);

	return ingredient;
}



