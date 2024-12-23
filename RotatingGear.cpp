#include "RotatingGear.h"




RotatingGear::RotatingGear(const CellPosition & gearposition,bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
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

    // Step 1: Print a message and wait for user input

    Output* pOut = pGrid->GetOutput(); // acces the output 
    Input* pIn = pGrid->GetInput();   // acces the input (maybe in don't it) ? 

    if (isClockWise)
        pOut->PrintMessage("You have reached a rotating gear. You will rotate clockwise. Click to continue...");
    else
        pOut->PrintMessage("You have reached a rotating gear. You will rotate counterclockwise. Click to continue...");

    int x;
    int y;

    pIn->GetPointClicked(x,y); // Wait for the player to click
    pOut->ClearStatusBar();

    // Step 2: Apply the rotation effect on the player
    if (isClockWise)
    {
        pPlayer->RotateClockwise(); // Rotate the player clockwise
    }
    else
    {
        pPlayer->RotateCounterClockwise(); // Rotate the player counterclockwise
    }
}
bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}

RotatingGear::~RotatingGear()
{
}
