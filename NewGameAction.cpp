#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"
#include "switchToPlayModeAction.h"
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
   Player *Ptr2_currPlayer = pGrid->GetCurrentPlayer();
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
	int l_avSize;
	int l_svSize;

	Command *l_avComm = Ptr2_currPlayer->GenerateAvailableCommands(l_avSize);
	Command *l_SavedComm = Ptr2_currPlayer->GetSavedCommands(l_svSize);

	pOut->CreateCommandsBar(l_SavedComm, l_svSize, l_avComm, l_avSize);
}

NewGameAction::~NewGameAction()
{
}