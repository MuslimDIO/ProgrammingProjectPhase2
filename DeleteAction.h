#pragma once
#include "Action.h"
#include "CellPosition.h"

class DeleteAction : public Action {
private:
    CellPosition cellPosition;

public:
    DeleteAction(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~DeleteAction();
};
