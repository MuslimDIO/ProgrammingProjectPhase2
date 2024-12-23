#include "AddFlagAction.h"


static int flagAdded = 0;
AddFlagAction::AddFlagAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
	

}


void AddFlagAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the flagPos
	pOut->PrintMessage("New Flag: Click on its Cell ...");
	flagPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (flagPos.IsValidCell() == false) {
		pOut->PrintMessage("Error: Invalid cell position! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	if (flagPos.GetCellNum() == 1)
	{
		pOut->PrintMessage("Error: Cell #1 is reserved for the player! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	if (flagAdded != 0)
	{
		pOut->PrintMessage("Error: there is already a Flag! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}



	// 5- Clear status bar
	pOut->ClearStatusBar();

}

void AddFlagAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a flag object
	Flag* pFlag = new Flag(flagPos);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3-Add the flag object to the GameObject of its Cell:
	
	if (flagAdded != 0)
	{
		pOut->PrintMessage("Error: there is already a Flag! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	bool added = pGrid->AddObjectToCell(pFlag);
	if (added == true)
	{
		pOut->PrintMessage("Flag added successfully");
		(flagAdded)++;
	}

	// 4-Check if the flag was added and print an errror message if flag couldn't be added
	if (added == false)
	{
		pOut->PrintMessage("Error: Cell already has an object! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		delete pFlag;


	}
}

AddFlagAction::~AddFlagAction()
{
}