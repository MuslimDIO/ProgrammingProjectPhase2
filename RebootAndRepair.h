#pragma once
#include "Action.h"
class RebootAndRepair :
    public Action
{


	RebootAndRepair(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); 
	virtual ~RebootAndRepair();
};

