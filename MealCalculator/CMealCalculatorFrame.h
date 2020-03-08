#pragma once

#include "AbsGui.h"

#include "CMeal.h"
#include "CIngredient.h"

class CMealCalculatorFrame : public MealCalculatorFrame
{
public:
	CMealCalculatorFrame(wxWindow* parent);
	~CMealCalculatorFrame();

private:
	CMeal* meal = nullptr;
	std::vector<CIngredient> mealIngredients;

private:
	void setEvents();
	void addIngredient(wxEvent& event);
	void removeIngredient(wxEvent& event);
	void clearIngredientTextCtrls();
	void selectIngredient(wxEvent& event);
	void showError(std::string message);
	void showInfo(std::string message);

	void addListBoxEntry(std::string);

	std::string getName();
	float getGrams();
	float getCalories();
	float getFat();
	float getCarbohydrates();
	float getProtein();
};

