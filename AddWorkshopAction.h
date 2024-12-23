#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "Workshop.h"

class AddWorkshopAction :public Action
{
	CellPosition WorkshopPos; //The position of the Workshop
public:
	AddWorkshopAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Creates a new Workshop Object 
	// then Sets this Workshop object to the GameObject Pointer of its Cell
	virtual ~AddWorkshopAction();


};

