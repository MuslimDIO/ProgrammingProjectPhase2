#include "PasteAction.h"
#include "Grid.h"
#include "CellPosition.h"
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
using namespace std;

PasteAction::PasteAction(ApplicationManager* pApp) : Action(pApp) {
    // Constructor initializes the base Action with the ApplicationManager pointer.
}

void PasteAction::ReadActionParameters() {
    // Get a Pointer to the Input / Output Interfaces
    Grid* pGrid = pManager->GetGrid();
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();

    // Ask the user to click on a cell
    pOut->PrintMessage("Click on the cell to paste the copied game object.");
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

void PasteAction::Execute() {
    // Ensure valid cell position was read
    ReadActionParameters();

    if (cellPosition.IsValidCell() == false) { 
        return;
    }

    // Get the Grid and Output pointers
    Grid* pGrid = pManager->GetGrid(); 
    Output* pOut = pGrid->GetOutput(); 

    // Retrieve the game object from the clipboard
    GameObject* pClipboardObject = pGrid->GetClipboard();
    if (pClipboardObject == nullptr) {
        pOut->PrintMessage("Clipboard is empty. No object to paste! Click to continue.");
        int x, y;
        pGrid->GetInput()->GetPointClicked(x, y);
        pOut->ClearStatusBar();
        return;
    }

    // Exclude pasting flags
    if (pClipboardObject->getObjType() == FLAG) {
        pOut->PrintMessage("Cannot paste a Flag. This type is excluded. Click to continue.");
        int x, y;
        pGrid->GetInput()->GetPointClicked(x, y);
        pOut->ClearStatusBar();
        return;
    }

    // Create a new object based on the type of the clipboard object with the correct position
    GameObject* pNewObject = nullptr;
    switch (pClipboardObject->getObjType()) {
   
    case WATERPIT:
        pNewObject = new WaterPit(cellPosition); // New WaterPit with updated position
        break;
    case DANGERZONE:
        pNewObject = new DangerZone(cellPosition); // New DangerZone with updated position
        break;
    case BELT: {
        Belt* belt = dynamic_cast<Belt*>(pClipboardObject);
        pNewObject = new Belt(cellPosition, belt->GetEndPosition()); // Maintain belt properties
        break;
    }
    case WORKSHOP:
        pNewObject = new Workshop(cellPosition); // New Workshop with updated position
        break;
    case ANTENNA:
        pNewObject = new Antenna(cellPosition); // New Antenna with updated position
        break;
    case ROTATING_GEAR:
        pNewObject = new RotatingGear(cellPosition); // New RotatingGear with updated position
        break;
    default:
        pOut->PrintMessage("Unknown game object type. Paste failed. Click to continue.");
        return;
    }

    // Attempt to add the new object to the selected cell
    if (pGrid->AddObjectToCell(pNewObject)) {
        string objectType;
        switch (pClipboardObject->getObjType()) {
        case FLAG: objectType = "Flag"; break;
        case WATERPIT: objectType = "Water Pit"; break;
        case DANGERZONE: objectType = "Danger Zone"; break;
        case BELT: objectType = "Belt"; break;
        case WORKSHOP: objectType = "Workshop"; break;
        case ANTENNA: objectType = "Antenna"; break;
        case ROTATING_GEAR: objectType = "Rotating Gear"; break;
        default: objectType = "Unknown"; break;
        }
        pOut->PrintMessage("Game object of type " + objectType + " pasted successfully at the selected cell. Click to continue.");
    }
    else {
        pOut->PrintMessage("Failed to paste the game object at the selected cell. It might already contain another object. Click to continue.");
        delete pNewObject;
    }
}

PasteAction::~PasteAction() {
    // Destructor
}
