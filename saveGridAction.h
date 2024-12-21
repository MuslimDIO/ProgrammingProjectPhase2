#ifndef _SAVE_GRID_H
#define _SAVE_GRID_H
#include "Action.h"
class SaveGrid : public Action
{
string _fileName;

public:
    SaveGrid(ApplicationManager *pApp);
    ~SaveGrid();
    virtual void ReadActionParameters() ;
    virtual void Execute() ;
 
};

#endif // _SAVE_GRID_H 