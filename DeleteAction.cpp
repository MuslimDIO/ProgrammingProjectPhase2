#include "DeleteAction.h"
#include "Grid.h"
#include "GameObject.h"
#include "Input.h"
#include "Output.h"
#include <string>

using namespace std;

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp) {
    // Constructor initializes the base Action with the ApplicationManager pointer.
}

void DeleteAction::ReadActionParameters() {
    // Get a Pointer to the Input / Output Interfaces
    Grid* pGrid = pManager->GetGrid();
    Input* pIn = pGrid->GetInput();
    Output* pOut = pGrid->GetOutput();

    // Ask the user to click on a cell
    pOut->PrintMessage("Click on the cell to delete the game object.");
    cellPosition = pIn->GetCellClicked();

    // Validate the cell position
    if (cellPosition.IsValidCell() == false) {
        pOut->PrintMessage("Invalid cell position! Click to continue.");
        int x, y;
        pIn->GetPointClicked(x, y); // Wait for the user to click
        pOut->ClearStatusBar();
        return;
    }
    pOut->ClearStatusBar();
    }

void DeleteAction::Execute() {
    // Ensure valid cell position was read
    ReadActionParameters();
    if (cellPosition.IsValidCell() == false) return;

    // Get the Grid and Output pointers
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();

    bool deleted = pGrid->RemoveObjectFromCell(cellPosition);
    //update interface
    pGrid->UpdateInterface();

    if (deleted == false) {
        pGrid->PrintErrorMessage("There is no GameObject here Click to continue");
    }
    else {
        pOut->PrintMessage("GameObject deleted successfully Click to continue");
        int x, y;
        pGrid->GetInput()->GetPointClicked(x, y);
        pOut->ClearStatusBar();
        return;
    }


    
}

DeleteAction::~DeleteAction() {
    
}
