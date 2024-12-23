#include "AddDangerZoneAction.h"

AddDangerZoneAction::AddDangerZoneAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddDangerZoneAction::ReadActionParameters()
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the "DangerZonePos" parameter
	pOut->PrintMessage("New DangerZone: Click on its Cell ...");
	DangerZonePos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (DangerZonePos.IsValidCell() == false) {
		pOut->PrintMessage("Error: Invalid cell position! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	if (DangerZonePos.GetCellNum() == 1)
	{
		pOut->PrintMessage("Error: Cell #1 is reserved for the player! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}

	
	// Clear messages
	pOut->ClearStatusBar();
}

void AddDangerZoneAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// 1-Create a DangerZone object
	DangerZone* pDangerZone = new DangerZone(DangerZonePos);

	// 2-Get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3-Add the DangerZone object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pDangerZone);

	// if the DangerZone cannot be added
	if (added == false)
	{
		pOut->PrintMessage("Error: Cell already has an object ! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		delete pDangerZone; 
	}
}

AddDangerZoneAction::~AddDangerZoneAction()
{
}



