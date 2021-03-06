///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#include <wx/statline.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MealCalculatorFrame
///////////////////////////////////////////////////////////////////////////////
class MealCalculatorFrame : public wxFrame
{
	private:

	protected:
		wxPanel* MainPanel;
		wxPanel* MealIngredientsPanel;
		wxListBox* MealIngredientsListBox;
		wxStaticText* m_staticText54;
		wxStaticText* IngredientsCountLabel;
		wxButton* RemoveIngredientButton;
		wxPanel* IngredientDetailsPanel;
		wxStaticText* m_staticText1;
		wxTextCtrl* IngredientNameTextCtrl;
		wxStaticText* m_staticText31;
		wxTextCtrl* IngredientBrandTextCtrl1;
		wxStaticText* m_staticText13;
		wxTextCtrl* IngredientCaloriesTextCtrl;
		wxStaticText* m_staticText14;
		wxTextCtrl* IngredientFatTextCtrl;
		wxStaticText* m_staticText16;
		wxTextCtrl* IngredientCarbohydratesTextCtrl;
		wxStaticText* m_staticText15;
		wxTextCtrl* IngredientProteinTextCtrl;
		wxTextCtrl* IngredientGramsTextCtrl;
		wxButton* IngredientButton;
		wxPanel* MealActionsPanel;
		wxButton* NewIngredientButton;
		wxFilePickerCtrl* LoadIngredientFilePicker;
		wxFilePickerCtrl* SaveIngredientFilePicker;
		wxStaticLine* m_staticline1;
		wxButton* ResetMealButton;
		wxFilePickerCtrl* LoadMealFilePicker;
		wxFilePickerCtrl* SaveMealFilePicker;
		wxStaticLine* m_staticline2;
		wxButton* CalculateButton;
		wxStatusBar* StatusBar;

	public:

		MealCalculatorFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Meal Calculator - v0.0.0"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 570,405 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MealCalculatorFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MealNutritionFrame
///////////////////////////////////////////////////////////////////////////////
class MealNutritionFrame : public wxFrame
{
	private:

	protected:
		wxPanel* MainPanel;
		wxPanel* m_panel20;
		wxStaticText* m_staticText3;
		wxTextCtrl* CaloriesTextCtrl;
		wxStaticText* m_staticText311;
		wxTextCtrl* CarbohydratesTextCtrl;
		wxStaticText* m_staticText31;
		wxTextCtrl* FatTextCtrl;
		wxStaticText* m_staticText3111;
		wxTextCtrl* ProteinTextCtrl;
		wxButton* CloseButton;

	public:

		MealNutritionFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Meal Nutrition"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 422,182 ), long style = wxDEFAULT_FRAME_STYLE|wxFRAME_FLOAT_ON_PARENT|wxTAB_TRAVERSAL );

		~MealNutritionFrame();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ConfirmationDialog
///////////////////////////////////////////////////////////////////////////////
class ConfirmationDialog : public wxDialog
{
	private:

	protected:
		wxPanel* MainPanel;
		wxStaticText* DialogStaticText;
		wxButton* OkButton;
		wxButton* CancelButton;

	public:

		ConfirmationDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Are you sure?"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP );
		~ConfirmationDialog();

};

