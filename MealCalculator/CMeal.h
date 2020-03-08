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

private:
	std::vector<CIngredient> ingredients;
};

