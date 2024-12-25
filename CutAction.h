#pragma once
#include "Action.h"
#include "CellPosition.h"

class CutAction : public Action {
private:
    CellPosition cellPosition; 

public:
    
    CutAction(ApplicationManager* pApp);

    
    virtual void ReadActionParameters();

    
    virtual void Execute();

    
    virtual ~CutAction();
};


