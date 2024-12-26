#include "RebootAndRepair.h"
#include "Player.h"
#include "Output.h"
#include "Input.h"
#include "Grid.h"
RebootAndRepair::RebootAndRepair(ApplicationManager* pApp) :Action(pApp)
{
}

void RebootAndRepair::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
}

void RebootAndRepair::Execute()
{
	ReadActionParameters();

    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

	Player* pPlayer = pGrid->GetCurrentPlayer(); // Get the current player
	Cell* currentCell = pPlayer->GetCell(); // Get the current cell of the player

    if (currentCell->HasWorkshop())
    {
        pOut->PrintMessage("The cell has a workshop.");
    }
    else
    {
        pOut->PrintMessage("The cell does not have a workshop.");
        int x, y;
		pIn->GetPointClicked(x, y);
        return;
    }


	Player* currentPlayer = pGrid->GetCurrentPlayer(); // Get the current player

    currentPlayer->setHealth(currentPlayer->getHealth() + 2); // increase player's health by my chosen number of 2 

	currentPlayer->setCanMove(false);  // disable movement for this turn

     pOut->PrintMessage("Reboot and Repair: Health increased by 2. Movement disabled for this turn.");
}

RebootAndRepair::~RebootAndRepair()
{
}