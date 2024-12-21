#include"switchToPlayModeAction.h"
#include"Grid.h"
#include"Output.h"
#include"Input.h"

switchToPlayModeAction::switchToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{
}
void switchToPlayModeAction::ReadActionParameters()
{
}

void switchToPlayModeAction::Execute()
{
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
    pOut->CreatePlayModeToolBar();
    pOut->ClearGridArea();
    pOut->CreatePlayModeToolBar();
    pOut->PrintMessage("Switched to Play Mode");
    pGrid->UpdateInterface();
}

switchToPlayModeAction::~switchToPlayModeAction()
{
}