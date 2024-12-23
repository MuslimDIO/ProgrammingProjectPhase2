#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"
class UseConsumable : public Action
{
public:
	UseConsumable(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads AddBeltAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new belt Object 
	// then Sets this belt object to the GameObject Pointer of its Cell


	virtual ~UseConsumable();
};

