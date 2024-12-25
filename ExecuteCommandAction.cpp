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
    Player *Ptr2_currPlayer = pGrid->GetCurrentPlayer();
    pOut->PrintMessage("Executing Saved Command");
    int x, y;
    pIn->GetPointClicked(x, y);

    int l_svSize;
    int l_avSize;
    Command *l_SavedComm = Ptr2_currPlayer->GetSavedCommands(l_svSize);

    Ptr2_currPlayer->Move(pGrid, l_SavedComm);

    for (int i = 0; i < l_svSize; i++)
    {
        l_SavedComm[i] = NO_COMMAND;
    }
    Ptr2_currPlayer->GenerateAvailableCommands(l_avSize);

    pGrid->UpdateInterface();
    pGrid->AdvanceCurrentPlayer();
    
    Ptr2_currPlayer = pGrid->GetCurrentPlayer();
    Command * l_avComm = Ptr2_currPlayer->GenerateAvailableCommands(l_avSize);
    pOut->CreateCommandsBar(l_SavedComm, l_svSize, l_avComm, l_avSize);
    // int selected = -1;
    // while (selected == -1)
    //{ // loop until a valid command is selected
    //     selected = pIn->GetSelectedCommandIndex();
    // }

    // bool l_saved = Ptr2_currPlayer->SaveCommand(selected);
    // if (!l_saved)
    //{
    //     pOut->PrintMessage("Command Cannot be saved Due to Maximum Capacity");
    //     return;
    // }
    // int l_avSize;

    // Command* l_avComm = Ptr2_currPlayer->GetAvailableCommands(l_avSize);

    // pOut->CreateCommandsBar(l_SavedComm, l_svSize, l_avComm, l_avSize);
    // pOut->PrintMessage("Command saved successfully");
}