
/**
 * @file ExecuteCommandAction.cpp
 * @brief Implementation of the ExecuteCommandAction class.
 *
 * This file contains the implementation of the ExecuteCommandAction class,
 * which is responsible for executing saved commands for the current player
 * in the game.
 * @author Omar Walid (Team Leader)
 */

#include "ExecuteCommandAction.h"
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include "Player.h"
enum Command;
/**
 * @brief Constructor for ExecuteCommandAction.
 *
 * Initializes a new instance of the ExecuteCommandAction class.
 *
 * @param pApp Pointer to the ApplicationManager.
 **/
ExecuteCommandAction::ExecuteCommandAction(ApplicationManager *pApp) : Action(pApp)
{
}

/**
 * @brief Destructor for ExecuteCommandAction.
 *
 * Cleans up any resources used by the ExecuteCommandAction instance.
 */
ExecuteCommandAction::~ExecuteCommandAction()
{
}
/**
 * @brief Reads the parameters required for the action.
 *
 * This function reads the necessary parameters for executing the action
 * from the input and output interfaces.
 */

void ExecuteCommandAction::ReadActionParameters()
{

    Grid *pGrid = pManager->GetGrid();
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();
}

/**
 * @brief Executes the saved command for the current player.
 *
 * This function performs the following steps:
 * - Reads the action parameters.
 * - Retrieves the current player and their saved commands.
 * - Executes the saved commands.
 * - Clears the saved commands.
 * - Generates available commands for the current player.
 * - Updates the game interface.
 * - Advances to the next player.
 * - Generates available commands for the new current player.
 * - Updates the commands bar in the game interface.
 */
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
    Command *l_avComm = Ptr2_currPlayer->GenerateAvailableCommands(l_avSize);
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