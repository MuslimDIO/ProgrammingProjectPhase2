/**
 * @file switchToPlayModeAction.cpp
 * @brief Implementation of the switchToPlayModeAction class.
 *
 * This file contains the implementation of the switchToPlayModeAction class,
 * which is responsible for switching the application to play mode.
 * @author Ibrahim Mohsen
 */

#include "switchToPlayModeAction.h"
#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include"Player.h"
enum Commad;
/**
 * @brief Constructor for the switchToPlayModeAction class.
 *
 * Initializes a new instance of the switchToPlayModeAction class.
 *
 * @param pApp Pointer to the ApplicationManager.
 */
switchToPlayModeAction::switchToPlayModeAction(ApplicationManager *pApp) : Action(pApp)
{
}
/**
 * @brief Reads the parameters required for the action.
 *
 * This method is overridden from the Action class but does not perform any
 * operations in this implementation.
 */

void switchToPlayModeAction::ReadActionParameters()
{
}

/**
 * @brief Executes the switch to play mode action.
 *
 * This method is responsible for switching the application to play mode by
 * updating the toolbar and grid area.
 */
void switchToPlayModeAction::Execute()
{

    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();
    Player * ptr2_currPlayer = pGrid->GetCurrentPlayer();  

    pOut->CreatePlayModeToolBar();
    
    pOut->ClearGridArea();
    int l_avSize ;
    int l_svSize;
    
    Command * l_avComm = ptr2_currPlayer->GenerateAvailableCommands(l_avSize);
    Command * l_SavedComm = ptr2_currPlayer->GetSavedCommands(l_svSize);
    pOut->CreateCommandsBar(l_SavedComm,l_svSize,l_avComm,l_avSize);
    pOut->PrintMessage("Switched to Play Mode");
    pGrid->UpdateInterface();
}


/**
 * @brief Destructor for the switchToPlayModeAction class.
 *
 * Cleans up any resources used by the switchToPlayModeAction class.
 */
switchToPlayModeAction::~switchToPlayModeAction()
{
}