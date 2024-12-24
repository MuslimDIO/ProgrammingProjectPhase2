
#include "Action.h"

class ExecuteCommandAction : public Action
{
public:
    ExecuteCommandAction(ApplicationManager* pApp);
    virtual ~ExecuteCommandAction();

    virtual void ReadActionParameters();
    virtual void Execute();
};

