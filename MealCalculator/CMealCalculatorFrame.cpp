#include "CMealCalculatorFrame.h"
#include <sstream>
#include "wx/msgdlg.h"



CMealCalculatorFrame::CMealCalculatorFrame(wxWindow* parent, std::string version) : MealCalculatorFrame(parent)
{
	SetTitle("Meal Calculator - v" + version);
	meal = new CMeal();

	setEvents();
	updateVisuals();
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
	LoadIngredientFilePicker->Bind(wxEVT_FILEPICKER_CHANGED, &CMealCalculatorFrame::loadIngredient, this);
	SaveIngredientFilePicker->Bind(wxEVT_FILEPICKER_CHANGED, &CMealCalculatorFrame::saveIngredient, this);

	ResetMealButton->Bind(wxEVT_BUTTON, &CMealCalculatorFrame::resetMeal, this);
	LoadMealFilePicker->Bind(wxEVT_FILEPICKER_CHANGED, &CMealCalculatorFrame::loadMeal, this);
	SaveMealFilePicker->Bind(wxEVT_FILEPICKER_CHANGED, &CMealCalculatorFrame::saveMeal, this);
}

/* Make any GUI changes */
void CMealCalculatorFrame::updateVisuals()
{
	// Load Ingredient Button
	wxWindow* loadIngredientButtonWindow = FindWindowByLabel("Browse", LoadIngredientFilePicker);
	loadIngredientButtonWindow->SetLabel("Load Ingredient");

	// Save Ingredient Button
	wxWindow* saveIngredientButtonWindow = FindWindowByLabel("Browse", SaveIngredientFilePicker);
	saveIngredientButtonWindow->SetLabel("Save Ingredient");

	// Load Meal Button
	wxWindow* loadMealButtonWindow = FindWindowByLabel("Browse", LoadMealFilePicker);
	loadMealButtonWindow->SetLabel("Load Meal");

	// Save Meal Button
	wxWindow* saveMealButtonWindow = FindWindowByLabel("Browse", SaveMealFilePicker);
	saveMealButtonWindow->SetLabel("Save Meal");
}

// Adds the current ingredient to the Meal
void CMealCalculatorFrame::addIngredient(wxEvent & event)
{
	CIngredient* newIngredient = getCurrentIngredient();
	if (!newIngredient)
		return;

	// Create ingredient and add to meal
	if (!meal->hasIngredient(newIngredient->getName()))
	{
		meal->addIngredient(*newIngredient);
		addListBoxEntry(newIngredient->getName());
		IngredientsCountLabel->SetLabelText(std::to_string(meal->getIngredientCount()));
		clearIngredientTextCtrls();
	}
	else
	{
		CIngredient* oldIngredient = meal->getIngredient(newIngredient->getName());
		oldIngredient->setGrams(newIngredient->getGrams());
		oldIngredient->setCaloriesPer100g(newIngredient->getCaloriesPer100g());
		oldIngredient->setFatPer100g(newIngredient->getFatPer100g());
		oldIngredient->setCarbohydratesPer100g(newIngredient->getCarbohydratesPer100g());
		oldIngredient->setProteinPer100g(newIngredient->getProteinPer100g());
	}

}


/* Gets the name of the currently selected ingredient */
/* Removes an ingredient from the Meal */
void CMealCalculatorFrame::removeIngredient(wxEvent & event)
{
	int selectedItemIndex = MealIngredientsListBox->GetSelection();
	if (selectedItemIndex == wxNOT_FOUND)
		return;

	std::string ingredientName = MealIngredientsListBox->GetString(selectedItemIndex).ToStdString();
	confirmationDialog = new CConfirmationDialog(this, "Remove " + ingredientName + " from the meal?");
	confirmationDialog->Center(wxBOTH);
	confirmationDialog->ShowModal();

	if (!confirmationDialog->wasConfirmed())
		return;

	// Remove ingredient from Meal
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

CIngredient* CMealCalculatorFrame::getCurrentIngredient()
{
	CIngredient* ingredient = nullptr;

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
		return ingredient;
	}

	if (grams == 0.0)
	{
		showError("Ingredient grams must be a number greater than zero");
		return ingredient;
	}

	if (calories == 0.0)
	{
		showError("Ingredient calories must be a number greater than zero");
		return ingredient;
	}

	ingredient = new CIngredient(
		name,
		grams,
		calories,
		fat,
		carbohydrates,
		protein
	);

	return ingredient;
}


/* Clears all ingredient Text Ctrls */
void CMealCalculatorFrame::newIngredient(wxEvent & event)
{
	confirmationDialog = new CConfirmationDialog(this, "Any unsaved information for this ingredient will be lost");
	confirmationDialog->Center(wxBOTH);
	confirmationDialog->ShowModal();

	if (!confirmationDialog->wasConfirmed())
		return;

	clearIngredientTextCtrls();

	IngredientNameTextCtrl->SetFocus();
	MealIngredientsListBox->DeselectAll();
}

/* Loads an ingredient from a file */
void CMealCalculatorFrame::loadIngredient(wxEvent& event)
{
	// TODO Add exception/error handling when user tries to load a file that 
	// isn't an ingredient
	CIngredient* ingredient = CIngredient::loadFromFile(LoadIngredientFilePicker->GetPath().ToStdString());
	if (!ingredient)
	{
		showError("The ingredient file could not be loaded. The data may be malformed or corrupted");
		return;
	}

	// Set Text Ctrl values
	IngredientNameTextCtrl->SetValue(ingredient->getName());
	IngredientCaloriesTextCtrl->SetValue(ingredient->getCaloriesPer100gString());
	IngredientFatTextCtrl->SetValue(ingredient->getFatPer100gString());
	IngredientCarbohydratesTextCtrl->SetValue(ingredient->getCarbohydratesPer100gString());
	IngredientProteinTextCtrl->SetValue(ingredient->getProteinPer100gString());
	
}

/* Saves the current ingredient to a file */
void CMealCalculatorFrame::saveIngredient(wxEvent& event)
{
	CIngredient* ingredient = getCurrentIngredient();
	if (!ingredient)
		return;

	ingredient->saveToFile(SaveIngredientFilePicker->GetPath().ToStdString());
	showInfo("Ingredient '" + ingredient->getName() + "' saved");
}

/* Clears all current meal ingredients and resets the ingredient form*/
void CMealCalculatorFrame::resetMeal(wxEvent& event)
{
	confirmationDialog = new CConfirmationDialog(this, "All ingredients will be removed and any unsaved changes will be lost");
	confirmationDialog->Center(wxBOTH);
	confirmationDialog->ShowModal();

	if (!confirmationDialog->wasConfirmed())
		return;

	meal->removeAllIngredients();
	MealIngredientsListBox->Clear();
	IngredientsCountLabel->SetLabelText(std::to_string(meal->getIngredientCount()));

	clearIngredientTextCtrls();
	IngredientNameTextCtrl->SetFocus();
	
}

/* Loads a meal file from disk */
void CMealCalculatorFrame::loadMeal(wxEvent& event)
{
	meal->loadFromFile(LoadMealFilePicker->GetPath().ToStdString());
	MealIngredientsListBox->Clear();
	clearIngredientTextCtrls();

	for (CIngredient ingredient : *(meal->getIngredients()))
	{
		addListBoxEntry(ingredient.getName());
	}

}

/* Saves the meal to disk */
void CMealCalculatorFrame::saveMeal(wxEvent& event)
{
	meal->saveToFile(SaveMealFilePicker->GetPath().ToStdString());
	showInfo("Meal saved");
}


/* Meal Ingredients ListBox selection event handler*/
void CMealCalculatorFrame::selectIngredient(wxEvent & event)
{
	int selectedItemIndex = MealIngredientsListBox->GetSelection();
	std::string ingredientName = MealIngredientsListBox->GetString(selectedItemIndex).ToStdString();
	CIngredient* ingredient =  meal->getIngredient(ingredientName);

	// Set Text Ctrl values
	char stringBuffer[10];

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
	wxMessageDialog(nullptr, message, "Error", wxICON_ERROR|wxCENTRE).ShowModal();

}

/* Creates and displays an info dialog */
void CMealCalculatorFrame::showInfo(std::string message)
{
	wxMessageDialog(nullptr, message, "Information", wxICON_INFORMATION|wxCENTRE).ShowModal();

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
	if (meal->getIngredientCount() <= 0)
	{
		showError("The meal must have at least one ingredient");
		return;
	}

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
	catch (const std::invalid_argument&)
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
	catch (const std::invalid_argument&)
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
	catch (const std::invalid_argument&)
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
	catch (const std::invalid_argument&)
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
	catch (const std::invalid_argument&)
	{
	}

	return iProtein;
}
