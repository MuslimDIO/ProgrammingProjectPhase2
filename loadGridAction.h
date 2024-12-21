#ifndef _LOADGRIDACTION_H
#define _LOADGRIDACTION_H
#include "Action.h"
#include <fstream>
#include <iostream>
using namespace std;

class LoadGridAction : public Action
{
string _fileName;
public:
    LoadGridAction(ApplicationManager* pApp); // A Constructor

    virtual void ReadActionParameters(); // Reads LoadGridAction action parameters (filename)

    virtual void Execute(); // Loads the Grid from a file

    virtual ~LoadGridAction(); // A Virtual Destructor
};


#endif