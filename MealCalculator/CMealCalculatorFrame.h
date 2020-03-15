#pragma once

#include "AbsGui.h"

#include "CMeal.h"
#include "CIngredient.h"
#include "CMealNutritionFrame.h"
#include "CConfirmationDialog.h"


class CMealCalculatorFrame : public MealCalculatorFrame
{
public:
	CMealCalculatorFrame(wxWindow* parent, std::string version);
	~CMealCalculatorFrame();

private:
	CMeal* meal = nullptr;
	std::vector<CIngredient> mealIngredients;
	CMealNutritionFrame* mealNutritionFrame;
	CConfirmationDialog* confirmationDialog;

private:
	void setEvents();
	void updateVisuals();
	void addIngredient(wxEvent& event);
	void removeIngredient(wxEvent& event);
	void clearIngredientTextCtrls();
	CIngredient* getCurrentIngredient();
	void selectIngredient(wxEvent& event);
	void updateIngredientButton(wxEvent& event);
	void showError(std::string message);
	void showInfo(std::string message);

	void resetIngredient(wxEvent& event);
	void loadIngredient(wxEvent& event);
	void saveIngredient(wxEvent& event);

	void resetMeal(wxEvent& event);
	void loadMeal(wxEvent& event);
	void saveMeal(wxEvent& event);

	void addListBoxEntry(std::string);
	void calculate(wxEvent& event);

	std::string getName();
	float getGrams();
	float getCalories();
	float getFat();
	float getCarbohydrates();
	float getProtein();
};

