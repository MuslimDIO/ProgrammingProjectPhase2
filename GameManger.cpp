#include "GameManger.h"
#include "UI_Info.h"
#include "Grid.h"
#include "Player.h"
GameManger::GameManger(ApplicationManager *pApp)
{
    ptr2_app = pApp;
    pGrid = ptr2_app->GetGrid();
    pOut = pGrid->GetOutput();
    pIn = pGrid->GetInput();
    _rounds = 0;
    _prevRounds = 0;
    _state = MOVING;
}

void GameManger ::incrementRound()
{
    _rounds++;
}
void GameManger ::GameMangerMain()
{
    if (UI.InterfaceMode == MODE_DESIGN)
        return;
  Player * ptr2_Curr = pGrid->GetCurrentPlayer();
  
     if (_rounds > _prevRounds)
    {
        _prevRounds = _rounds;
        _state = SHOOTING;
    }
    else if (ptr2_Curr->GetCell()->HasFlag()) {
        _state =WIN;    
    }
    
}