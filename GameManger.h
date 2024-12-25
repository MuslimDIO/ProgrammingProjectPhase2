// Scrapped idea 
#ifndef _GAME_MANGER_H
#define _GAME_MANGER_H
#include "ApplicationManager.h"

#include "DEFS.h"
#include "UI_Info.h"

class Input;
class Output;
class Grid;
class GameManger
{
    ApplicationManager *ptr2_app;
    int _rounds;
    int _prevRounds;
    enum gameState
    {
        SHOOTING,
        MOVING,
        WIN
    } _state;
    Input *pIn;
    Output *pOut;
    Grid *pGrid;
    
public:
    GameManger(ApplicationManager *app);
    void incrementRound();
    void GameMangerMain();
};

#endif