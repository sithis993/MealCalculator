#pragma once

#include "AbsGui.h"

#include "CMeal.h"
#include "CIngredient.h"
#include "CMealNutritionFrame.h"

class CMealCalculatorFrame : public MealCalculatorFrame
{
public:
	CMealCalculatorFrame(wxWindow* parent);
	~CMealCalculatorFrame();

private:
	CMeal* meal = nullptr;
	std::vector<CIngredient> mealIngredients;
	CMealNutritionFrame* mealNutritionFrame;

private:
	void setEvents();
	void addIngredient(wxEvent& event);
	void removeIngredient(wxEvent& event);
	void clearIngredientTextCtrls();
	void selectIngredient(wxEvent& event);
	void updateIngredientButton(wxEvent& event);
	void showError(std::string message);
	void showInfo(std::string message);

	void addListBoxEntry(std::string);
	void calculate(wxEvent& event);
	void closeMealNutritionFrame(wxEvent& event);

	std::string getName();
	float getGrams();
	float getCalories();
	float getFat();
	float getCarbohydrates();
	float getProtein();
};

