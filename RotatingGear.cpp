#include "RotatingGear.h"
#include <fstream>
#include <iostream>
#include "Player.h"
using namespace std;



RotatingGear::RotatingGear(const CellPosition & gearposition) : GameObject(gearposition, ROTATING_GEAR)
{
	isClockWise = true;
}
RotatingGear::RotatingGear(const CellPosition & gearposition,bool a_clockWise) : GameObject(gearposition, ROTATING_GEAR)
{
	isClockWise = a_clockWise;
}

void RotatingGear::Draw(Output* pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	//2- Apply the roating gear's effect by rotating the player according to the direction

	// abdallah saad :) 

    
    // Step 1: Access the Output and Input interfaces
    Output* pOut = pGrid->GetOutput(); // Access the Output
    Input* pIn = pGrid->GetInput();   // Access the Input (maybe not important)

    CellPosition pos;
    bool validCell = false;

    
    while (!validCell) // making infint loop untill the user click valied cell
    {
        // Print a message based on the rotation 
        if (isClockWise)
        {
            pOut->PrintMessage("You have reached a rotating gear. You will rotate clockwise. Click on a valid cell to continue...");
        }
        else
        {
            pOut->PrintMessage("You have reached a rotating gear. You will rotate counterclockwise. Click on a valid cell to continue...");
        }

        
        pos = pIn->GetCellClicked(); // Wait for the player to click and get the CellPosition

        // Check if the cell is valid

        if (pos.IsValidCell())
        {
            validCell = true; // Exit the loop if the cell is valid
        }
        else
        {
            pOut->PrintMessage("Invalid cell position! Please try again.");
        }
    }

    //  Apply the rotation effect to the player

    pPlayer->ClearDrawing(pOut);

    /*switch (pPlayer->direction)
    {
    case UP:
        pPlayer->direction = isClockWise ? RIGHT : LEFT;
       
        break;
    case RIGHT:
        pPlayer->direction = isClockWise ? DOWN : UP;
        break;
    case DOWN:
        pPlayer->direction = isClockWise ? LEFT : RIGHT;
        break;
    case LEFT:
        pPlayer->direction = isClockWise ? UP : DOWN;
        break;
    }*/

    // Clear the status bar
    pOut->ClearStatusBar();
}

bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}
void RotatingGear::setIsClockWise(bool a_isClockWise)
{
	isClockWise = a_isClockWise;
}
void RotatingGear::Save(ofstream & OutFile, GameObject_Type type)
{
	if (type == ROTATING_GEAR)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << " " << isClockWise << endl;
	}
}
void RotatingGear::Load(ifstream &Infile, GameObject_Type type)
{
	if (type == ROTATING_GEAR)
	{
		int l_cellNum;
		bool l_clockwise;
		Infile >> l_cellNum >> l_clockwise; // Read the cell number
		CellPosition cellPos = GetPosition().GetCellPositionFromNum(l_cellNum);
		position = cellPos;
		isClockWise = l_clockwise;
	}
}	
RotatingGear::~RotatingGear()
{
}
