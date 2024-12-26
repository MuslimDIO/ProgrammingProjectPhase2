#include "AddAntennaAction.h"

int AntennaAdded = 0;
AddAntennaAction::AddAntennaAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void AddAntennaAction::ReadActionParameters()
{

	// 1- Get a Pointer to the Input / Output Interfaces from the Application Manager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Read the Antenna Position
	pOut->PrintMessage("New Antenna: Click on the cell ...");
	AntennaPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters
	if (AntennaPos.IsValidCell() == false) {
		pOut->PrintMessage("Error: Invalid cell position! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	if (AntennaPos.GetCellNum() == 1)
	{
		pOut->PrintMessage("Error: Cell #1 is reserved for the player! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	if (AntennaAdded != 0)
	{
		pOut->PrintMessage("Error: there is already an Antenna! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}

	// 3- Clear messages
	pOut->ClearStatusBar();
}

void AddAntennaAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// 1- Create a Antenna object
	Antenna* pAntenna = new Antenna(AntennaPos);

	// 2- Get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	
	// 3-Add the Antenna object to the GameObject of its Cell:

	if (AntennaAdded != 0)
	{
		pOut->PrintMessage("Error: there is already an Antenna! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		return;
	}
	bool added = pGrid->AddObjectToCell(pAntenna);
	if (added == true)
	{
		pOut->PrintMessage("Antenna added successfully");
		(AntennaAdded)++;
	}

	// 4- check if the Antenna cannot be added
	if (added == false)
	{
		pOut->PrintMessage("Error: Cell already has an object ! Click to continue...");
		int x, y;
		pIn->GetPointClicked(x, y);
		delete pAntenna;
	}
}

AddAntennaAction::~AddAntennaAction()
{
}
