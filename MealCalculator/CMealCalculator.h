#pragma once


#include <vector>
#include "wx/wx.h"

#include "CMealCalculatorFrame.h"
#include "CIngredient.h"

class CMealCalculator : public wxApp
{
public:
	CMealCalculator();
	~CMealCalculator();

private:
	CMealCalculatorFrame* mealCalculatorFrame = nullptr;
	std::vector<CIngredient> mealIngredients;

public:
	virtual bool OnInit();

};

