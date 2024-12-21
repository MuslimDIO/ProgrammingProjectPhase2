#include "Flag.h"
#include "Output.h"

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

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a flag. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a flag. Click to continue ...");
	// 2- Apply the flag's effect by ending the game
	//    Review the "pGrid" functions and decide which function can be used for that
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
Flag::~Flag()
{

}