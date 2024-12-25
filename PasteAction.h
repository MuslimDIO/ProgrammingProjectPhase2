#pragma once
#include "Action.h"
#include "CellPosition.h"

class PasteAction : public Action {
private:
    CellPosition cellPosition; 

public:
    
    PasteAction(ApplicationManager* pApp);

    
    virtual void ReadActionParameters();

    
    virtual void Execute();

    
    virtual ~PasteAction();
};
