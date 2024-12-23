#include "DangerZone.h"
#include <iostream>
#include <fstream>
using namespace std;
DangerZone::DangerZone(const CellPosition &dangerZonePosition) : GameObject(dangerZonePosition, DANGERZONE)
{
}

void DangerZone::Draw(Output *pOut) const
{
	pOut->DrawDangerZone(position);
}

void DangerZone::Apply(Grid *pGrid, Player *pPlayer)
{
	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a danger zone. Click to continue ..." and wait mouse click

	// 2- Apply the danger zone's effect by reducing the health of the player by 1
	// 3- Update the players info which is displayed (check Grid class and decide which function to use) ++
}

DangerZone::~DangerZone()
{
}
void DangerZone::Save(ofstream &OutFile, GameObject_Type type)
{
	if (type == DANGERZONE)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << endl;
	}
}

 void DangerZone::Load(ifstream &Infile, GameObject_Type type)
{
	if (type == DANGERZONE)
	{
		int cellNum;
		Infile >> cellNum; // Read the cell number
		CellPosition cellPos = GetPosition().GetCellPositionFromNum(cellNum);
        position = cellPos;
	}
}