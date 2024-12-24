#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include"switchToPlayModeAction.h"
NewGameAction::NewGameAction(ApplicationManager *pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
}
class Action;
void NewGameAction::Execute()
{
	Grid *pGrid = pManager->GetGrid();
	Output *pOut = pGrid->GetOutput();

	pGrid->SetEndGame(0);

	CellPosition start(1);

	for (int i = 0; i < MaxPlayerCount; i++)
	{

		Player *pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pPlayer->Restart();
		pGrid->AdvanceCurrentPlayer();
	}

	pGrid->ResetCurrentPlayerNum();

	Action *ptr2_action=new switchToPlayModeAction(pManager);
	ptr2_action->Execute();
	delete ptr2_action;
}

NewGameAction::~NewGameAction()
{
}