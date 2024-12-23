#include "AddBeltAction.h"

AddBeltAction::AddBeltAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddBeltAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Belt: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Belt: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters
	if (startPos.IsValidCell() == false || startPos.GetCellNum() == 1) {
		pOut->PrintMessage("Error: Invalid start cell position! Cannot be cell #1. Click to continue...");
		startPos = CellPosition(-1, -1);
		return;
	}
	if (endPos.IsValidCell() == false || endPos.GetCellNum() == 1) {
		pOut->PrintMessage("Error: Invalid end cell position! Cannot be cell #1. Click to continue...");
		endPos = CellPosition(-1, -1);
		return;
	}

	if  (startPos.VCell() != endPos.VCell() || startPos.HCell() != endPos.HCell()) {
		pOut->PrintMessage("Error: End cell must be in the same row or column as the start cell. Click to continue...");
		endPos = CellPosition(-1, -1);
		startPos = CellPosition(-1, -1);
		return;
	}

	/*if (pGrid->GetGameObject(startPos) != nullptr || pGrid->GetGameObject(endPos) != nullptr) {
		pOut->PrintMessage("Error: Start or end cell already contains a game object. Click to continue...");
		startPos = CellPosition(-1, -1);
		endPos = CellPosition(-1, -1);
		return;
	}*/

	

	// Clear messages
	pOut->ClearStatusBar();
}

void AddBeltAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a belt object with the parameters read from the user
	Belt * pBelt = new Belt(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

										
	bool added = pGrid->AddObjectToCell(pBelt);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the belt is created and added to the GameObject of its Cell, so we finished executing the AddBeltAction

}


AddBeltAction::~AddBeltAction()
{
}
