#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include "DangerZone.h"
class AddDangerZoneAction :public Action
{

	CellPosition DangerZonePos; //The position of the DangerZone
public:
	AddDangerZoneAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads action parameters 
	virtual void Execute(); // Creates a new DangerZone Object 
	// then Sets this DangerZone object to the GameObject Pointer of its Cell
	virtual ~AddDangerZoneAction();


};

