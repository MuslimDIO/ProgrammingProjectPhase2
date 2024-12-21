#include "RotatingGear.h"
#include <fstream>
#include <iostream>
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
