#include "WaterPit.h"
#include <iostream>
#include <fstream>
using namespace std;
WaterPit::WaterPit(const CellPosition &waterPitPosition) : GameObject(waterPitPosition, WATERPIT)
{
}

void WaterPit::Draw(Output *pOut) const
{
	pOut->DrawWaterPit(position);
}

void WaterPit::Apply(Grid *pGrid, Player *pPlayer)
{

	/// TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message, make sure to edit this message according to which player wins "You drowned in a water pit. Player (0/1) wins !  Click to continue ..." and wait mouse click

	// 2- Apply the water pit's effect by setting the player's health which drowned to zero and ending the game
	// 3- Update the players info which is displayed (check Grid class and decide which function to use)
}

 void WaterPit::Save(ofstream &OutFile, GameObject_Type type)
{
	if (type == WATERPIT)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << endl;
	}
}
WaterPit::~WaterPit()
{
}
