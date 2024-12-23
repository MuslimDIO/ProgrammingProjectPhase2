#include "UseConsumable.h"
#include "ApplicationManager.h"

UseConsumable::UseConsumable(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}




void UseConsumable::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Would you like to use the 1. ToolKit or 2. Hacking Device");
	// Read the cell position
	int choice = pIn->GetInteger(pOut);
	// Clear messages
	pOut->ClearStatusBar();
}



void UseConsumable::Execute()
{
	
}

UseConsumable::~UseConsumable() {

}