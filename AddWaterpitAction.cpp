#include "AddWaterpitAction.h"

AddWaterpitAction::AddWaterpitAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddWaterpitAction::ReadActionParameters()
{

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the WaterpitPos
	pOut->PrintMessage("New Waterpit: Click on its Cell ...");
	WaterpitPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (WaterpitPos.IsValidCell() == false) {
		pOut->PrintMessage("Error: Invalid cell position! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	if (WaterpitPos.GetCellNum() == 1)
	{
		pOut->PrintMessage("Error: Cell #1 is reserved for the player! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}

	// 5- Clear status bar
	pOut->ClearStatusBar();

}

void AddWaterpitAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	// 1-Create a Waterpit object
	WaterPit* pWaterpit = new WaterPit(WaterpitPos);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3-Add the Waterpit object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pWaterpit);

	// if the Waterpit cannot be added
	if (added == false)
	{
		pOut->PrintMessage("Error: Cell already has an object ! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		delete pWaterpit; 
	}
}

AddWaterpitAction::~AddWaterpitAction()
{
}


