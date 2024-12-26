#include "CutAction.h"
#include "Grid.h"
#include "Flag.h"
#include "WaterPit.h"
#include "DangerZone.h"
#include "Belt.h"
#include "Workshop.h"
#include "Antenna.h"
#include "RotatingGear.h"
#include "GameObject.h"
#include "Input.h"
#include "Output.h"
#include <string>
extern int flagAdded;
extern int AntennaAdded;
using namespace std;

CutAction::CutAction(ApplicationManager *pApp) : Action(pApp)
{
    // Constructor initializes the base Action with the ApplicationManager pointer.
}

void CutAction::ReadActionParameters()
{
    // Get a Pointer to the Input / Output Interfaces
    Grid *pGrid = pManager->GetGrid();
    Input *pIn = pGrid->GetInput();
    Output *pOut = pGrid->GetOutput();

    // Ask the user to click on a cell
    pOut->PrintMessage("Click on the cell to cut the game object.");
    cellPosition = pIn->GetCellClicked();

    // Validate the cell position
    if (cellPosition.IsValidCell() == false)
    {
        pOut->PrintMessage("Invalid cell position! Click to continue.");
        int x, y;
        pIn->GetPointClicked(x, y); // Wait for the user to click
        pOut->ClearStatusBar();
        return;
    }
    pOut->ClearStatusBar();
}

void CutAction::Execute()
{
    // Ensure valid cell position was read
    ReadActionParameters();
    if (cellPosition.IsValidCell() == false)
    {
        return;
    }

    // Get the Grid and Output pointers
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();

    // Add the cell position to the clipboard
    pGrid->SetClipboard(&cellPosition);

    // Retrieve the game object from the selected cell
    GameObject *pGameObject = nullptr;
    pGrid->RemoveObjectFromCell(cellPosition); // This will remove the object from the cell
    pGameObject = pGrid->GetClipboard();       //  GetClipboard returns the last object added to clipboard

    if (pGameObject)
    {
        if (dynamic_cast<Flag *>(pGameObject))
        {
            flagAdded--;
        }
        if (dynamic_cast<Antenna *>(pGameObject))
        {
            AntennaAdded--;
        }
    }
    // check if set clipboard added a valid object to clipboard

    if (pGameObject == nullptr)
    {
    pGameObject = pGrid->GetClipboard(); //  GetClipboard returns the last object added to clipboard 
// check if set clipboard added a valid object to clipboard

    if (pGameObject == nullptr) {
        pOut->PrintMessage("No game object in the selected cell to cut. Click to continue.");
        int x, y;
        pGrid->GetInput()->GetPointClicked(x, y);
        pOut->ClearStatusBar();
        return;
    }

    // Provide feedback on the successful cut operation
    string objectType;
    switch (pGameObject->getObjType())
    {
    case FLAG:
        objectType = "Flag";
        break;
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
    case ANTENNA:
        objectType = "Antenna";
        break;
    case ROTATING_GEAR:
        objectType = "Rotating Gear";
        break;
    default:
        objectType = "Unknown";
        break;
    }
    pOut->PrintMessage("Game object of type " + objectType + " cut successfully. Click to continue.");
}

CutAction::~CutAction()
{
}
