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

	size_t getIngredientCount();

private:
	std::vector<CIngredient> ingredients;
};

