#include "CMealNutritionFrame.h"



CMealNutritionFrame::CMealNutritionFrame(wxWindow* parent) : MealNutritionFrame(parent)
{
	setEvents();
	GetParent()->Disable();
}


CMealNutritionFrame::~CMealNutritionFrame()
{
}

/* Sets up Frame event handling */
void CMealNutritionFrame::setEvents()
{
	CloseButton->Bind(wxEVT_BUTTON, &CMealNutritionFrame::closeFrame, this);
	Bind(wxEVT_CLOSE_WINDOW, &CMealNutritionFrame::closeFrame, this);
}

/* Sets the Meal calories Text Ctrl */
void CMealNutritionFrame::setCalories(float mealCalories)
{
	// TODO Review issue with buffer size and stack overvflows
	char stringBuffer[100];
	sprintf(stringBuffer, "%.2f", mealCalories);

	CaloriesTextCtrl->SetValue(std::string(stringBuffer));
}

/* Sets the Meal Fat Text Ctrl */
void CMealNutritionFrame::setFat(float mealFat)
{
	char stringBuffer[100];
	sprintf(stringBuffer, "%.2f", mealFat);

	FatTextCtrl->SetValue(std::string(stringBuffer));
}

void CMealNutritionFrame::setCarbohydrates(float mealCarbohydrates)
{
	char stringBuffer[100];
	sprintf(stringBuffer, "%.2f", mealCarbohydrates);

	CarbohydratesTextCtrl->SetValue(std::string(stringBuffer));
}

void CMealNutritionFrame::setProtein(float mealProtein)
{
	char stringBuffer[100];
	sprintf(stringBuffer, "%.2f", mealProtein);

	ProteinTextCtrl->SetValue(std::string(stringBuffer));
}

/* Closes the Frame */
void CMealNutritionFrame::closeFrame(wxEvent & event)
{
	GetParent()->Enable();
	Destroy();
}


