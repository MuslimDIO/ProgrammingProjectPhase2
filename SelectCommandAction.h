#ifndef _SELECTCOMMANDACTION_H
#define _SELECTCOMMANDACTION_H
#include "Action.h"

class SelectCommandAction : public Action
{
public:
    SelectCommandAction(ApplicationManager *pApp);
    virtual ~SelectCommandAction();

    virtual void ReadActionParameters();
    virtual void Execute();
};

#endif