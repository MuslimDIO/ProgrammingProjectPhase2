#include "NewGameAction.h"
#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp)
	: Action(pApp)
{

}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	pGrid->SetEndGame(0);
	
	CellPosition start(1);
	

	
	for (int i = 0; i < MaxPlayerCount; i++) {

		Player* pPlayer = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(pPlayer, start);
		pPlayer->Restart();
		pGrid->AdvanceCurrentPlayer();
	}
	pGrid->ResetCurrentPlayerNum();
}

NewGameAction::~NewGameAction()
{

}