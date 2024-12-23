
#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "WaterPit.h"

class AddWaterpitAction
{
	CellPosition WaterpitPos; //The position of the Waterpit
public:
	AddWaterpitAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Creates a new Waterpit Object 
	// then Sets this Waterpit object to the GameObject Pointer of its Cell
	virtual ~AddWaterpitAction();

};

