#include "Belt.h"
#include <iostream>
#include <fstream>
using namespace std;	

Belt::Belt(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos, BELT)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

	// abdallah saas :)
// (check the validation of the start and end posittion and check the start is not the end position)
	// (  had ebka e7l el error )

		if (!startCellPos.IsValidCell() || !endCellPos.IsValidCell() || startCellPos == endCellPos)
		{
			throw " Invalid Belt positions ";
		}
		endCellPos = endCellPos;
	
}
void Belt::Draw(Output* pOut) const
{
	pOut->DrawBelt(position, endCellPos);
}

void Belt::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a belt. Click to continue ..." and wait mouse click

	// 2- Apply the belt's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that

	// abdallah saad start (first time) :)

	// Step 1: Print a message and wait for a mouse click
	////pGrid->PrintErrorMessage("You  have  reached a belt.Click to continue");
	
	// Step 2: Move the player to the belt's end position
	////pGrid->UpdatePlayerCell(pPlayer, endCellPos);

	// abdallah saad start (second time) :)

	// access input and output

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("You have reached a belt.Click to continue"); // Print a message

	// Wait for a mouse click (get coordinates)
	int x, y; //// Declare variables to store the click coordinates 
	pIn->GetPointClicked(x, y);

	// Move the player to the end position
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}
CellPosition Belt::GetEndPosition() const
{
	return endCellPos;
}


Belt::~Belt()
{
}
void Belt::Save(ofstream & OutFile, GameObject_Type type)
{
	if (type == BELT)
	{
      CellPosition l_startPos = GetPosition();
	  

	  OutFile << l_startPos.GetCellNum() <<"  "<< endCellPos.GetCellNum() << endl;
	}

}

void Belt::Load(ifstream & Infile, GameObject_Type type)
{
	if (type == BELT)
	{
		int startCellNum, endCellNum;
        Infile >> startCellNum >> endCellNum; // Read start and end cell numbers
	    CellPosition l_endpos = GetEndPosition().GetCellPositionFromNum(endCellNum);
		CellPosition l_startpos = GetPosition().GetCellPositionFromNum(startCellNum);
		position = l_startpos;
		endCellPos = l_endpos;
	}
}