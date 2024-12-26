#include "WaterPit.h"
#include <iostream>
#include <fstream>
#include "Player.h"
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

	// abdallah saad :) 

	
	Output* pOut = pGrid->GetOutput(); // access the output 
	Input* pIn = pGrid->GetInput();   // acess the input

	pOut->PrintMessage("You have fallen into a water pit! Your health will drop to zero and the game will end. Click to continue...");
	int x, y;
	pIn->GetPointClicked(x, y); // Wait for user input
	pOut->ClearStatusBar();

 
	pPlayer->setHealth(0); // Set the player's health to zero

	
	pOut->PrintMessage("You felt in water pit .... game over "); // print game over 
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();

	
	pGrid->SetEndGame(true); // End the game


}



 void WaterPit::Save(ofstream &OutFile, GameObject_Type type)
{
	if (type == WATERPIT)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << endl;
	}
}
void WaterPit::Load(ifstream &Infile, GameObject_Type type)
{
	if (type == WATERPIT)
	{
		int cellNum;
		Infile >> cellNum; // Read the cell number
		CellPosition cellPos = GetPosition().GetCellPositionFromNum(cellNum);
		position = cellPos;
	}
}
WaterPit::~WaterPit()
{
}
