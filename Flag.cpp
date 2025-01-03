#include "Flag.h"
#include "Output.h"
#include"Player.h"

#include <iostream>
#include <fstream>
using namespace std;

Flag::Flag(const CellPosition & flagposition) : GameObject(flagposition,FLAG)
{

}

void Flag::Draw(Output* pOut) const
{
	pOut->DrawFlag(position);
}

void Flag::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput(); // access the output
	Input* pIn = pGrid->GetInput();   // acess the input

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a flag. Click to continue ..." and wait mouse click
	pOut->PrintMessage("You have reached a flag. Click to continue ...");
	int x, y;
	pIn->GetPointClicked(x,y); // Wait for user input
	// 2- Apply the flag's effect by ending the game
	//    Review the "pGrid" functions and decide which function can be used for that

	pPlayer->setReachedFlag(true);

	pGrid->SetEndGame(true);
	

}



void Flag::Save(ofstream &OutFile, GameObject_Type type)
{
	if (type == FLAG)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << endl;
	}
}

void Flag::Load(ifstream &Infile, GameObject_Type type)
{
	if (type == FLAG)
	{
		int cellNum;
		Infile >> cellNum; // Read the cell number
		CellPosition cellPos = GetPosition().GetCellPositionFromNum(cellNum);
		position = cellPos;
	}
}
Flag::~Flag()
{

}