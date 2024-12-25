#include "ExecuteCommandAction.h"
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Player.h"
enum Command;
ExecuteCommandAction::ExecuteCommandAction(ApplicationManager *pApp) : Action(pApp)
{
}

ExecuteCommandAction::~ExecuteCommandAction()
{
}

void ExecuteCommandAction::ReadActionParameters()
{

    Grid *pGrid = pManager->GetGrid();
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();
}

void ExecuteCommandAction::Execute()
{

    ReadActionParameters();
    Grid *pGrid = pManager->GetGrid();
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();
    Player *pPlayer = pGrid->GetCurrentPlayer();
    pOut->PrintMessage("Executing Saved Command");
    int x, y;
    pIn->GetPointClicked(x, y);

    int savedCommSize;
    int availCommSize;
    Command *savedCommands = pPlayer->GetSavedCommands(savedCommSize);

    pPlayer->Move(pGrid, savedCommands);
    for (int i = 0; i < availCommSize; i++)
    {
        savedCommands[i] = NO_COMMAND;
    }
    pPlayer->GenerateAvailableCommands(availCommSize);

    Command *availableCommands = pPlayer->GenerateAvailableCommands(availCommSize);

    pOut->CreateCommandsBar(savedCommands, savedCommSize, availableCommands, availCommSize);
    pGrid->UpdateInterface();
    pGrid->AdvanceCurrentPlayer();
     pPlayer = pGrid->GetCurrentPlayer();
   pPlayer->GenerateAvailableCommands(availCommSize);
    
}