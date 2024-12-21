#ifndef _SWITCH_TO_PLAY_MODE_ACTION_H
#define _SWITCH_TO_PLAY_MODE_ACTION_H
#include "Action.h"
class switchToPlayModeAction : public Action
{
   
public:
    virtual void ReadActionParameters();
    virtual void Execute();

    switchToPlayModeAction(ApplicationManager* pApp);
    ~switchToPlayModeAction();
};




#endif // _SWITCH_TO_PLAY_MODE_ACTION_H