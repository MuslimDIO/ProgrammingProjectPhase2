#include "CopyAction.h"
#include "Grid.h"
#include "CellPosition.h"
#include "GameObject.h"
#include "Input.h"
#include "Output.h"
#include <string>

using namespace std;

CopyAction::CopyAction(ApplicationManager *pApp) : Action(pApp)
{
    // Constructor initializes the base Action with the ApplicationManager pointer.
}

void CopyAction::ReadActionParameters()
{
    // Get a Pointer to the Input / Output Interfaces
    Grid *pGrid = pManager->GetGrid();
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();

    // Ask the user to click on a cell
    pOut->PrintMessage("Click on the cell to copy the game object.");
    cellPosition = pIn->GetCellClicked();

    // Validate the cell position
    if (cellPosition.IsValidCell() == false)
    {
        pOut->PrintMessage("Error: Invalid cell position! Click to continue...");
        int x, y;
        pIn->GetPointClicked(x, y);
        return;
    }
    pOut->ClearStatusBar();
}

void CopyAction::Execute()
{
    // Ensure valid cell position was read
    ReadActionParameters();

    if (cellPosition.IsValidCell() == false) {
        return;
    }
    // Get the Grid and Output pointers
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();

    // Use Grid's GetClipboard and SetClipboard functions to manage the object
    
    if (pGrid->SetClipboard(&cellPosition))
    {
        GameObject *pGameObject = pGrid->GetClipboard();
        // Exclude copying flags
        if (pGameObject->getObjType() == FLAG) {
            pOut->PrintMessage("Cannot copy a Flag. This type is excluded. Click to continue.");
            int x, y;
            pGrid->GetInput()->GetPointClicked(x, y);
            pOut->ClearStatusBar();
            return;
        }
        // Exclude copying antennas
        if (pGameObject->getObjType() == ANTENNA) {
            pOut->PrintMessage("Cannot copy an antenna. This type is excluded. Click to continue.");
            int x, y;
            pGrid->GetInput()->GetPointClicked(x, y);
            pOut->ClearStatusBar();
            return;
        }
        if (pGameObject)
        {
            string objectType;
            switch (pGameObject->getObjType())
            {
            
            case WATERPIT:
                objectType = "Water Pit";
                break;
            case DANGERZONE:
                objectType = "Danger Zone";
                break;
            case BELT:
                objectType = "Belt";
                break;
            case WORKSHOP:
                objectType = "Workshop";
                break;
          
            case ROTATING_GEAR:
                objectType = "Rotating Gear";
                break;
            
            }
            pOut->PrintMessage("Game object of type " + objectType + " copied successfully. Click to continue.");
        }
        else
        {
            pOut->PrintMessage("No game object in the selected cell. Copy failed. Click to continue.");
        }
    }
    else
    {
        pOut->PrintMessage("Copy failed. Click to continue.");
    }


   
}

CopyAction::~CopyAction()
{
}
