/**
 * @file SelectCommandAction.cpp
 * @brief Implementation of the SelectCommandAction class.
 *
 * This file contains the implementation of the SelectCommandAction class,
 * which is responsible for handling the action of selecting a command
 * from the available commands bar in the application.
 *
 * The SelectCommandAction class inherits from the Action class and
 * overrides the ReadActionParameters and Execute methods to perform
 * the specific action of selecting and saving a command.
 *
 * The class interacts with various components such as Grid, Input,
 * Output, and Player to achieve its functionality.
 *
 * @see SelectCommandAction
 * @see Action
 * @see Grid
 * @see Input
 * @see Output
 * @see Player
 * @author Ibrahim Mohsen
 */
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

    bool l_saved = Ptr2_currPlayer->SaveCommand(selected);
    if (!l_saved)
    {
        pOut->PrintMessage("Command Cannot be saved Due to Maximum Capacity");
        return;
    }
    int l_avSize;
    int l_svSize;

    Command *l_avComm = Ptr2_currPlayer->GetAvailableCommands(l_avSize);
    Command *l_SavedComm = Ptr2_currPlayer->GetSavedCommands(l_svSize);

    pOut->CreateCommandsBar(l_SavedComm, l_svSize, l_avComm, l_avSize);
    pOut->PrintMessage("Command saved successfully");
}