#include "CMealCalculatorFrame.h"
#include <sstream>
#include "wx/msgdlg.h"



CMealCalculatorFrame::CMealCalculatorFrame(wxWindow* parent) : MealCalculatorFrame(parent)
{
	SetTitle("Meal Calculator - v0.2.0");
	meal = new CMeal();

	setEvents();
}


CMealCalculatorFrame::~CMealCalculatorFrame()
{
}

// Set up event handlers (Timers, Buttons etc.)
void CMealCalculatorFrame::setEvents()
{

	IngredientButton->Bind(wxEVT_BUTTON, &CMealCalculatorFrame::addIngredient, this);
	RemoveIngredientButton->Bind(wxEVT_BUTTON, &CMealCalculatorFrame::removeIngredient, this);
	MealIngredientsListBox->Bind(wxEVT_LISTBOX, &CMealCalculatorFrame::selectIngredient, this);
	IngredientNameTextCtrl->Bind(wxEVT_TEXT, &CMealCalculatorFrame::updateIngredientButton, this);
	CalculateButton->Bind(wxEVT_BUTTON, &CMealCalculatorFrame::calculate, this);
	NewIngredientButton->Bind(wxEVT_BUTTON, &CMealCalculatorFrame::newIngredient, this);
}

// Adds the current ingredient to the Meal
void CMealCalculatorFrame::addIngredient(wxEvent & event)
{
	// Get field data
	std::string name = getName();
	float grams = getGrams();
	float calories = getCalories();
	float fat = getFat();
	float carbohydrates = getCarbohydrates();
	float protein = getProtein();

	// Valdiate fields
	// TODO Check to see if an ingredient with this name alreay exists?
	// Actually here we'll just want to update the values, so not create another
	if (name.empty())
	{
		showError("Ingredient must have a name");
		return;
	}

	if (grams == 0.0)
	{
		showError("Ingredient grams must be a number greater than zero");
		return;
	}

	if (calories == 0.0)
	{
		showError("Ingredient calories must be a number greater than zero");
		return;
	}


	// Create ingredient and add to meal
	if (!meal->hasIngredient(name))
	{
		CIngredient* ingredient = new CIngredient(
			name,
			grams,
			calories,
			fat,
			carbohydrates,
			protein
		);
		meal->addIngredient(*ingredient);
		addListBoxEntry(name);
		IngredientsCountLabel->SetLabelText(std::to_string(meal->getIngredientCount()));
		clearIngredientTextCtrls();
	}
	else
	{
		CIngredient* ingredient = meal->getIngredient(name);
		ingredient->setGrams(grams);
		ingredient->setCaloriesPer100g(calories);
		ingredient->setFatPer100g(fat);
		ingredient->setCarbohydratesPer100g(carbohydrates);
		ingredient->setProteinPer100g(protein);
	}
}

/* Gets the name of the currently selected ingredient */
/* Removes an ingredient from the Meal */
void CMealCalculatorFrame::removeIngredient(wxEvent & event)
{
	int selectedItemIndex = MealIngredientsListBox->GetSelection();
	if (selectedItemIndex == wxNOT_FOUND)
		return;

	// Remove ingredient from Meal
	std::string ingredientName = MealIngredientsListBox->GetString(selectedItemIndex).ToStdString();
	meal->removeIngredient(ingredientName);

	// Remove List Box selection and clear form 
	MealIngredientsListBox->Delete(selectedItemIndex);
	IngredientsCountLabel->SetLabelText(std::to_string(meal->getIngredientCount()));
	clearIngredientTextCtrls();

}

/* Clears the Ingredient detail Text Ctrls */
void CMealCalculatorFrame::clearIngredientTextCtrls()
{
	IngredientNameTextCtrl->Clear();
	IngredientGramsTextCtrl->Clear();
	IngredientCaloriesTextCtrl->Clear();
	IngredientFatTextCtrl->Clear();
	IngredientCarbohydratesTextCtrl->Clear();
	IngredientProteinTextCtrl->Clear();

}

/* Clears all ingredient Text Ctrls making it easier to add/create a new ingredient */
void CMealCalculatorFrame::newIngredient(wxEvent & event)
{
	IngredientNameTextCtrl->Clear();
	IngredientGramsTextCtrl->Clear();
	IngredientCaloriesTextCtrl->Clear();
	IngredientFatTextCtrl->Clear();
	IngredientCarbohydratesTextCtrl->Clear();
	IngredientProteinTextCtrl->Clear();

	IngredientNameTextCtrl->SetFocus();
	MealIngredientsListBox->DeselectAll();
}


/* Meal Ingredients ListBox selection event handler*/
void CMealCalculatorFrame::selectIngredient(wxEvent & event)
{
	int selectedItemIndex = MealIngredientsListBox->GetSelection();
	std::string ingredientName = MealIngredientsListBox->GetString(selectedItemIndex).ToStdString();
	CIngredient* ingredient =  meal->getIngredient(ingredientName);

	// Set Text Ctrl values
	char stringBuffer[100];

	// Name
	IngredientNameTextCtrl->SetValue(ingredient->getName());

	// Grams
	sprintf(stringBuffer, "%.2f", ingredient->getGrams());
	IngredientGramsTextCtrl->SetValue(std::string(stringBuffer));

	// Calories
	sprintf(stringBuffer, "%.2f", ingredient->getCaloriesPer100g());
	IngredientCaloriesTextCtrl->SetValue(std::string(stringBuffer));

	// Fat
	sprintf(stringBuffer, "%.2f", ingredient->getFatPer100g());
	IngredientFatTextCtrl->SetValue(std::string(stringBuffer));

	// Carbohydrates
	sprintf(stringBuffer, "%.2f", ingredient->getCarbohydratesPer100g());
	IngredientCarbohydratesTextCtrl->SetValue(std::string(stringBuffer));

	// Protein
	sprintf(stringBuffer, "%.2f", ingredient->getProteinPer100g());
	IngredientProteinTextCtrl->SetValue(std::string(stringBuffer));
}

void CMealCalculatorFrame::updateIngredientButton(wxEvent & event)
{
	if (meal->hasIngredient(getName()))
	{
		IngredientButton->SetLabelText("Update Ingredient");
	}
	else
	{
		IngredientButton->SetLabelText("Add to Meal");
	}

}


/* Creates and displays an error dialog */
void CMealCalculatorFrame::showError(std::string message)
{
	wxMessageDialog(nullptr, message, "Error", wxICON_ERROR).ShowModal();

}

/* Creates and displays an info dialog */
void CMealCalculatorFrame::showInfo(std::string message)
{
	wxMessageDialog(nullptr, message, "Information", wxICON_INFORMATION).ShowModal();

}

/* Adds an item to the Meal Ingredients ListBox */
void CMealCalculatorFrame::addListBoxEntry(std::string entry)
{
	wxArrayString strings = wxArrayString();
	strings.Add(entry);
	MealIngredientsListBox->InsertItems(strings, MealIngredientsListBox->GetCount());
}

/* Gets the Meal's nutrition and displays it in the Meal Nutrition Frame */
void CMealCalculatorFrame::calculate(wxEvent & event)
{
	mealNutritionFrame = new CMealNutritionFrame(this);

	mealNutritionFrame->setCalories(meal->getCaloriesPer100g());
	mealNutritionFrame->setFat(meal->getFatPer100g());
	mealNutritionFrame->setCarbohydrates(meal->getCarbohydratesPer100g());
	mealNutritionFrame->setProtein(meal->getProteinPer100g());

	mealNutritionFrame->Show();
}

/* Get the current value of the Ingredient Name TextCtrl */
std::string CMealCalculatorFrame::getName()
{
	return IngredientNameTextCtrl->GetValue().ToStdString();
}

/* Gets the current value of the Ingredient Grams TextCtrl */
float CMealCalculatorFrame::getGrams()
{
	float iGrams = 0.f;
	std::string sGrams = IngredientGramsTextCtrl->GetValue().ToStdString();

	try
	{
		iGrams = std::stof(sGrams);
	}
	catch (const std::invalid_argument& ia)
	{
	}

	return iGrams;
}

/* Get the current value of the Ingredient Calories TextCtrl */
float CMealCalculatorFrame::getCalories()
{
	float iCalories = 0.f;
	std::string sCalories = IngredientCaloriesTextCtrl->GetValue().ToStdString();

	try
	{
		iCalories = std::stof(sCalories);
	}
	catch (const std::invalid_argument& ia)
	{
	}

	return iCalories;
}

/* Get the current value of the Ingredient Fat TextCtrl */
float CMealCalculatorFrame::getFat()
{
	float iFat = 0.f;
	std::string sFat = IngredientFatTextCtrl->GetValue().ToStdString();

	try
	{
		iFat = std::stof(sFat);
	}
	catch (const std::invalid_argument& ia)
	{
	}

	return iFat;
}

/* Get the current value of the Ingredient Carbohydrates TextCtrl */
float CMealCalculatorFrame::getCarbohydrates()
{
	float iCarbohydrates = 0.f;
	std::string sCarbohydrates = IngredientCarbohydratesTextCtrl->GetValue().ToStdString();

	try
	{
		iCarbohydrates = std::stof(sCarbohydrates);
	}
	catch (const std::invalid_argument& ia)
	{
	}

	return iCarbohydrates;
}

/* Get the current value of the Ingredient Protein TextCtrl */
float CMealCalculatorFrame::getProtein()
{
	float iProtein = 0.f;
	std::string sProtein = IngredientProteinTextCtrl->GetValue().ToStdString();

	try
	{
		iProtein = std::stof(sProtein);
	}
	catch (const std::invalid_argument& ia)
	{
	}

	return iProtein;
}
