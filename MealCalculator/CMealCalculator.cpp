#include "CMealCalculator.h"

wxIMPLEMENT_APP(CMealCalculator);

CMealCalculator::CMealCalculator()
{
}


CMealCalculator::~CMealCalculator()
{
}

bool CMealCalculator::OnInit()
{
	mealCalculatorFrame = new CMealCalculatorFrame(nullptr, VERSION_STRING);
	mealCalculatorFrame->Show();

	mealCalculatorFrame->Center(wxBOTH);
	return true;
}
