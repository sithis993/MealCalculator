///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "AbsGui.h"

///////////////////////////////////////////////////////////////////////////

MealCalculatorFrame::MealCalculatorFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	MainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	MealIngredientsPanel = new wxPanel( MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( MealIngredientsPanel, wxID_ANY, wxT("Meal Ingredients") ), wxVERTICAL );

	MealIngredientsListBox = new wxListBox( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	sbSizer1->Add( MealIngredientsListBox, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Total"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	bSizer87->Add( m_staticText54, 0, wxALL, 5 );


	bSizer87->Add( 0, 0, 1, wxEXPAND, 5 );

	IngredientsCountLabel = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	IngredientsCountLabel->Wrap( -1 );
	bSizer87->Add( IngredientsCountLabel, 0, wxALL, 5 );


	sbSizer1->Add( bSizer87, 0, wxEXPAND, 5 );


	bSizer4->Add( sbSizer1, 1, wxEXPAND, 5 );

	RemoveIngredientButton = new wxButton( MealIngredientsPanel, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( RemoveIngredientButton, 0, wxALL|wxEXPAND, 5 );


	MealIngredientsPanel->SetSizer( bSizer4 );
	MealIngredientsPanel->Layout();
	bSizer4->Fit( MealIngredientsPanel );
	bSizer5->Add( MealIngredientsPanel, 1, wxEXPAND | wxALL, 5 );

	IngredientDetailsPanel = new wxPanel( MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* IngredientDetailsSizer;
	IngredientDetailsSizer = new wxStaticBoxSizer( new wxStaticBox( IngredientDetailsPanel, wxID_ANY, wxT("Ingredient Details") ), wxVERTICAL );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1 = new wxStaticText( IngredientDetailsSizer->GetStaticBox(), wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer61->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer61->Add( 0, 0, 1, wxEXPAND, 5 );

	IngredientNameTextCtrl = new wxTextCtrl( IngredientDetailsSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( IngredientNameTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	IngredientDetailsSizer->Add( bSizer61, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( IngredientDetailsSizer->GetStaticBox(), wxID_ANY, wxT("Brand"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer81->Add( m_staticText31, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer81->Add( 0, 0, 1, wxEXPAND, 5 );

	IngredientBrandTextCtrl1 = new wxTextCtrl( IngredientDetailsSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( IngredientBrandTextCtrl1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	IngredientDetailsSizer->Add( bSizer81, 1, wxEXPAND, 5 );


	bSizer6->Add( IngredientDetailsSizer, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* IngredientNutritionSizer;
	IngredientNutritionSizer = new wxStaticBoxSizer( new wxStaticBox( IngredientDetailsPanel, wxID_ANY, wxT("Nutrition (per 100g)") ), wxVERTICAL );

	wxBoxSizer* bSizer613;
	bSizer613 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxT("Calories"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer613->Add( m_staticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer613->Add( 0, 0, 1, wxEXPAND, 5 );

	IngredientCaloriesTextCtrl = new wxTextCtrl( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer613->Add( IngredientCaloriesTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	IngredientNutritionSizer->Add( bSizer613, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer614;
	bSizer614 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText14 = new wxStaticText( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxT("Fat (g)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer614->Add( m_staticText14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer614->Add( 0, 0, 1, wxEXPAND, 5 );

	IngredientFatTextCtrl = new wxTextCtrl( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer614->Add( IngredientFatTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	IngredientNutritionSizer->Add( bSizer614, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer616;
	bSizer616 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText16 = new wxStaticText( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxT("Carbohydrates (g)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer616->Add( m_staticText16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer616->Add( 0, 0, 1, wxEXPAND, 5 );

	IngredientCarbohydratesTextCtrl = new wxTextCtrl( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer616->Add( IngredientCarbohydratesTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	IngredientNutritionSizer->Add( bSizer616, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer615;
	bSizer615 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText15 = new wxStaticText( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxT("Protein (g)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer615->Add( m_staticText15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer615->Add( 0, 0, 1, wxEXPAND, 5 );

	IngredientProteinTextCtrl = new wxTextCtrl( IngredientNutritionSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer615->Add( IngredientProteinTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	IngredientNutritionSizer->Add( bSizer615, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );


	IngredientNutritionSizer->Add( bSizer34, 1, wxEXPAND, 5 );


	bSizer6->Add( IngredientNutritionSizer, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* IngredientGramsSizer;
	IngredientGramsSizer = new wxStaticBoxSizer( new wxStaticBox( IngredientDetailsPanel, wxID_ANY, wxT("Grams") ), wxVERTICAL );

	IngredientGramsTextCtrl = new wxTextCtrl( IngredientGramsSizer->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER|wxTE_PROCESS_ENTER );
	IngredientGramsSizer->Add( IngredientGramsTextCtrl, 0, wxALL|wxEXPAND, 5 );

	IngredientButton = new wxButton( IngredientGramsSizer->GetStaticBox(), wxID_ANY, wxT("Add to Meal"), wxDefaultPosition, wxDefaultSize, 0 );
	IngredientGramsSizer->Add( IngredientButton, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( IngredientGramsSizer, 1, wxEXPAND, 5 );


	IngredientDetailsPanel->SetSizer( bSizer6 );
	IngredientDetailsPanel->Layout();
	bSizer6->Fit( IngredientDetailsPanel );
	bSizer5->Add( IngredientDetailsPanel, 1, wxALL|wxEXPAND, 5 );

	MealActionsPanel = new wxPanel( MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( MealActionsPanel, wxID_ANY, wxT("Meal Actions") ), wxVERTICAL );

	NewIngredientButton = new wxButton( sbSizer6->GetStaticBox(), wxID_ANY, wxT("New Ingredient"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer6->Add( NewIngredientButton, 0, wxALL|wxEXPAND, 5 );

	LoadIngredientFilePicker = new wxFilePickerCtrl( sbSizer6->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Load Ingredient"), wxT("*.ing"), wxDefaultPosition, wxDefaultSize, wxFLP_OPEN );
	sbSizer6->Add( LoadIngredientFilePicker, 0, wxALL|wxEXPAND, 5 );

	SaveIngredientFilePicker = new wxFilePickerCtrl( sbSizer6->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Save Ingredient"), wxT("*.ing"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE );
	sbSizer6->Add( SaveIngredientFilePicker, 0, wxALL|wxEXPAND, 5 );

	m_staticline1 = new wxStaticLine( sbSizer6->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer6->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	ResetMealButton = new wxButton( sbSizer6->GetStaticBox(), wxID_ANY, wxT("Reset Meal"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer6->Add( ResetMealButton, 0, wxALL|wxEXPAND, 5 );

	LoadMealFilePicker = new wxFilePickerCtrl( sbSizer6->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Load Meal"), wxT("meal (*.meal)|*.meal"), wxDefaultPosition, wxDefaultSize, wxFLP_FILE_MUST_EXIST|wxFLP_OPEN );
	sbSizer6->Add( LoadMealFilePicker, 0, wxALL|wxEXPAND, 5 );

	SaveMealFilePicker = new wxFilePickerCtrl( sbSizer6->GetStaticBox(), wxID_ANY, wxEmptyString, wxT("Save Meal"), wxT("meal (*.meal)|*.meal"), wxDefaultPosition, wxDefaultSize, wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE );
	sbSizer6->Add( SaveMealFilePicker, 0, wxALL|wxEXPAND, 5 );

	m_staticline2 = new wxStaticLine( sbSizer6->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer6->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );


	sbSizer6->Add( 0, 0, 1, wxEXPAND, 5 );

	CalculateButton = new wxButton( sbSizer6->GetStaticBox(), wxID_ANY, wxT("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer6->Add( CalculateButton, 0, wxALL|wxEXPAND, 5 );


	MealActionsPanel->SetSizer( sbSizer6 );
	MealActionsPanel->Layout();
	sbSizer6->Fit( MealActionsPanel );
	bSizer5->Add( MealActionsPanel, 1, wxEXPAND | wxALL, 5 );


	MainPanel->SetSizer( bSizer5 );
	MainPanel->Layout();
	bSizer5->Fit( MainPanel );
	bSizer1->Add( MainPanel, 1, wxEXPAND | wxALL, 0 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );
}

MealCalculatorFrame::~MealCalculatorFrame()
{
}

MealNutritionFrame::MealNutritionFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );

	MainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxVERTICAL );

	m_panel20 = new wxPanel( MainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer18;
	sbSizer18 = new wxStaticBoxSizer( new wxStaticBox( m_panel20, wxID_ANY, wxT("Per 100g") ), wxVERTICAL );

	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( sbSizer18->GetStaticBox(), wxID_ANY, wxT("Calories"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer8->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer8->Add( 0, 0, 1, wxEXPAND, 5 );

	CaloriesTextCtrl = new wxTextCtrl( sbSizer18->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer8->Add( CaloriesTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer89->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer811;
	bSizer811 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText311 = new wxStaticText( sbSizer18->GetStaticBox(), wxID_ANY, wxT("Carbohydrates"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText311->Wrap( -1 );
	bSizer811->Add( m_staticText311, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer811->Add( 0, 0, 1, wxEXPAND, 5 );

	CarbohydratesTextCtrl = new wxTextCtrl( sbSizer18->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer811->Add( CarbohydratesTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer89->Add( bSizer811, 1, wxEXPAND, 5 );


	bSizer88->Add( bSizer89, 1, 0, 5 );

	wxBoxSizer* bSizer90;
	bSizer90 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( sbSizer18->GetStaticBox(), wxID_ANY, wxT("Fat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer81->Add( m_staticText31, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer81->Add( 0, 0, 1, wxEXPAND, 5 );

	FatTextCtrl = new wxTextCtrl( sbSizer18->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer81->Add( FatTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer90->Add( bSizer81, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8111;
	bSizer8111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3111 = new wxStaticText( sbSizer18->GetStaticBox(), wxID_ANY, wxT("Protein"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3111->Wrap( -1 );
	bSizer8111->Add( m_staticText3111, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer8111->Add( 0, 0, 1, wxEXPAND, 5 );

	ProteinTextCtrl = new wxTextCtrl( sbSizer18->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer8111->Add( ProteinTextCtrl, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer90->Add( bSizer8111, 1, wxEXPAND, 5 );


	bSizer88->Add( bSizer90, 1, 0, 5 );


	sbSizer18->Add( bSizer88, 1, 0, 5 );


	m_panel20->SetSizer( sbSizer18 );
	m_panel20->Layout();
	sbSizer18->Fit( m_panel20 );
	MainSizer->Add( m_panel20, 0, wxALL, 5 );

	CloseButton = new wxButton( MainPanel, wxID_ANY, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	MainSizer->Add( CloseButton, 0, wxALL|wxEXPAND, 5 );


	MainPanel->SetSizer( MainSizer );
	MainPanel->Layout();
	MainSizer->Fit( MainPanel );
	bSizer24->Add( MainPanel, 1, wxALL, 0 );


	this->SetSizer( bSizer24 );
	this->Layout();

	this->Centre( wxBOTH );
}

MealNutritionFrame::~MealNutritionFrame()
{
}

ConfirmationDialog::ConfirmationDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );

	MainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );


	bSizer29->Add( 0, 0, 1, wxEXPAND, 5 );

	DialogStaticText = new wxStaticText( MainPanel, wxID_ANY, wxT("Message here"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	DialogStaticText->Wrap( 100 );
	bSizer29->Add( DialogStaticText, 0, wxALL|wxEXPAND, 10 );


	bSizer29->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer30->Add( bSizer29, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );


	bSizer33->Add( 0, 0, 1, wxEXPAND, 5 );

	OkButton = new wxButton( MainPanel, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( OkButton, 0, wxALL, 5 );

	CancelButton = new wxButton( MainPanel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( CancelButton, 0, wxALL, 5 );


	bSizer30->Add( bSizer33, 1, wxALIGN_RIGHT, 5 );


	MainPanel->SetSizer( bSizer30 );
	MainPanel->Layout();
	bSizer30->Fit( MainPanel );
	bSizer28->Add( MainPanel, 0, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer28 );
	this->Layout();
	bSizer28->Fit( this );

	this->Centre( wxBOTH );
}

ConfirmationDialog::~ConfirmationDialog()
{
}
