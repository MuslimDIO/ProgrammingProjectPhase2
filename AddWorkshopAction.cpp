#include "AddWorkshopAction.h"

AddWorkshopAction::AddWorkshopAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddWorkshopAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Application Manager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the Workshop Position
	pOut->PrintMessage("New Workshop: Click on the cell ...");
	WorkshopPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (WorkshopPos.IsValidCell() == false) {
		pOut->PrintMessage("Error: Invalid cell position! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	if (WorkshopPos.GetCellNum() == 1)
	{
		pOut->PrintMessage("Error: Cell #1 is reserved for the player! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}

	// 3- Clear messages
	pOut->ClearStatusBar();
}

void AddWorkshopAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// 1- Create a Workshop object
	Workshop* pWorkshop = new Workshop(WorkshopPos);

	// 2- Get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3- Add the Workshop object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pWorkshop);

	// 4- if the Workshop cannot be added
	if (added == false)
	{
		pOut->PrintMessage("Error: Cell already has an object ! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		delete pWorkshop;
	}
}

AddWorkshopAction::~AddWorkshopAction()
{
}