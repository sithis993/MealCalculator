#include <string>
#include <fstream>

#pragma once

/* Represents a Meal Ingredient */
class CIngredient
{
public:
	CIngredient(
		std::string name,
		std::string brand,
		float grams, 
		float calories, 
		float fat,
		float carbohydrates,
		float protein
	);
	~CIngredient();

public:
	std::string getName();
	std::string getBrand();
	float getGrams();
	float getCaloriesPer100g();
	float getFatPer100g();
	float getCarbohydratesPer100g();
	float getProteinPer100g();

	std::string getGramsString();
	std::string getCaloriesPer100gString();
	std::string getFatPer100gString();
	std::string getCarbohydratesPer100gString();
	std::string getProteinPer100gString();

	float getTotalCalories();
	float getTotalFat();
	float getTotalCarbohydrates();
	float getTotalProtein();

	void setBrand(std::string brand);
	void setGrams(float grams);
	void setCaloriesPer100g(float calories);
	void setFatPer100g(float fat);
	void setCarbohydratesPer100g(float carbohydrates);
	void setProteinPer100g(float protein);

	void saveToFile(std::string path);
	static CIngredient* loadFromFile(std::string path);

private:
	std::string name;
	std::string brand;
	float grams;
	float caloriesPer100g;
	float fatPer100g;
	float carbohydratesPer100g;
	float proteinPer100g;
};

