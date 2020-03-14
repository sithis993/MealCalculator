#include "CConfirmationDialog.h"

CConfirmationDialog::CConfirmationDialog(wxWindow* parent, std::string message) : ConfirmationDialog(parent)
{
	DialogStaticText->SetLabel(message);
	DialogStaticText->Wrap(400); // Wrap after 300 pixels
	Fit(); // Update size

	setEvents();
}

CConfirmationDialog::~CConfirmationDialog()
{
}

/* Set event handlers */
void CConfirmationDialog::setEvents()
{
	OkButton->Bind(wxEVT_BUTTON, &CConfirmationDialog::setConfirmed, this);
	CancelButton->Bind(wxEVT_BUTTON, &CConfirmationDialog::closeDialog, this);
}

/* Checks if the user pressed the OK button */
boolean CConfirmationDialog::wasConfirmed()
{
	return confirmed;
}

/* Sets the Confirmation dialog as having been confirmed by the user */
void CConfirmationDialog::setConfirmed(wxEvent& event)
{
	confirmed = true;
	closeDialog(event);
}

/* Closes the Confirmaton Dialog */
void CConfirmationDialog::closeDialog(wxEvent& event)
{
	EndModal(0);
}
