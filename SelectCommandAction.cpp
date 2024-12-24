#include "SelectCommandAction.h"
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Player.h"
enum Command;
SelectCommandAction::SelectCommandAction(ApplicationManager *pApp) : Action(pApp)
{
}

SelectCommandAction::~SelectCommandAction()
{
}

void SelectCommandAction::ReadActionParameters()
{

    Grid *pGrid = pManager->GetGrid();
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();
    pOut->PrintMessage("Select a command from the available commands bar");

}

void SelectCommandAction::Execute()
{

    ReadActionParameters();
    Grid *pGrid = pManager->GetGrid();
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();
    Player *Ptr2_currPlayer = pGrid->GetCurrentPlayer();
    int selected = -1;
    while (selected == -1)
    { // loop until a valid command is selected
        selected = pIn->GetSelectedCommandIndex();
    }

    bool l_saved=Ptr2_currPlayer->SaveCommand(selected);
    if (!l_saved)
    {
        pOut->PrintMessage("Command  Cannot saved Due to Maximum Capacity");
        return;
    }
    int l_avSize;
    int l_svSize;

    Command *l_avComm = Ptr2_currPlayer->GetAvailableCommands(l_avSize);
    Command *l_SavedComm = Ptr2_currPlayer->GetSavedCommands(l_svSize);

    pOut->CreateCommandsBar(l_SavedComm, l_svSize, l_avComm, l_avSize);
    pOut->PrintMessage("Command saved successfully");
}