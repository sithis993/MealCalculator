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
#include <wx/frame.h>

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
		wxStaticText* m_staticText3;
		wxTextCtrl* IngredientGramsTextCtrl;
		wxStaticText* m_staticText13;
		wxTextCtrl* IngredientCaloriesTextCtrl;
		wxStaticText* m_staticText14;
		wxTextCtrl* IngredientFatTextCtrl;
		wxStaticText* m_staticText16;
		wxTextCtrl* IngredientCarbohydratesTextCtrl;
		wxStaticText* m_staticText15;
		wxTextCtrl* IngredientProteinTextCtrl;
		wxButton* IngredientButton;
		wxPanel* MealActionsPanel;
		wxButton* m_button3;
		wxButton* m_button4;
		wxButton* m_button5;

	public:

		MealCalculatorFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Meal Calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,370 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

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
		wxTextCtrl* m_textCtrl3;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_textCtrl31;
		wxStaticText* m_staticText311;
		wxTextCtrl* m_textCtrl311;
		wxStaticText* m_staticText3111;
		wxTextCtrl* m_textCtrl3111;
		wxButton* CloseButton;

	public:

		MealNutritionFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Meal Nutrition"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 377,227 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MealNutritionFrame();

};

