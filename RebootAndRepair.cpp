#include "RebootAndRepair.h"
#include "Player.h"
#include "Output.h"

RebootAndRepair:: RebootAndRepair(ApplicationManager* pApp) :Action(pApp)
{
}

void RebootAndRepair::ReadActionParameters()
{
}

void RebootAndRepair::Execute()
{
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