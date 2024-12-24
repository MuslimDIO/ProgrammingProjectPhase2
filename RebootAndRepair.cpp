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

	Player* currentPlayer = pGrid->GetCurrentPlayer(); // Get the current player

    currentPlayer->SetHealth(currentPlayer->GetHealth() + 2); // increase player's health by my chosen number of 2 

	currentPlayer->setCanMove(false);  // disable movement for this turn

     pOut->PrintMessage("Reboot and Repair: Health increased by 2. Movement disabled for this turn.");
}

RebootAndRepair::~RebootAndRepair()
{
}