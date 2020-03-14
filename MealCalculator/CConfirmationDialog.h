#pragma once
#include "AbsGui.h"
class CConfirmationDialog : public ConfirmationDialog
{
public:
	CConfirmationDialog(wxWindow* parent, std::string message);
	~CConfirmationDialog();

private:
	bool confirmed = false;
	void setEvents();
	void setConfirmed(wxEvent& event);
	void closeDialog(wxEvent& event);

public:
	boolean wasConfirmed();
};

