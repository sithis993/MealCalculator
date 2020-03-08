#pragma once
#include "AbsGui.h"

class CMealNutritionFrame : public MealNutritionFrame
{
public:
	CMealNutritionFrame(wxWindow* parent);
	~CMealNutritionFrame();

public:
	void setEvents();
	void setCalories(float mealCalories);
	void setFat(float mealFat);
	void setCarbohydrates(float mealCarbohydrates);
	void setProtein(float mealProtein);

private:
	void closeFrame(wxEvent& event);
};

