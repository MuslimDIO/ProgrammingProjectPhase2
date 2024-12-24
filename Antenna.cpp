#include "Antenna.h"
#include <iostream> 
#include <fstream>
#include "Grid.h"
#include "Player.h"
#include "Output.h"
#include "Input.h"
#include <cmath> // For abs function

using namespace std;



void Antenna::Save(ofstream & OutFile, GameObject_Type type)
{
	if (type == ANTENNA)
	{
      CellPosition cellPos = GetPosition();
	  

	  OutFile << cellPos.GetCellNum() << endl;
	}
}

void Antenna::Load(ifstream & Infile, GameObject_Type type)
{
	if (type == ANTENNA)
	{
		int cellNum;
		Infile >> cellNum;
		CellPosition cellPos = CellPosition::GetCellPositionFromNum(cellNum);
		position = cellPos;
	}
}
Antenna::Antenna(const CellPosition & antennaPosition):GameObject(antennaPosition, ANTENNA)
{
}

void Antenna::Draw(Output * pOut) const
{
	pOut->DrawAntenna(position);
}

void Antenna::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "the antenna will decide the turn of players. Click to continue ..." and wait mouse click

	// 2- Apply the antenna effect by following these notes, check grid class and decide which function to use
	//The antenna determines the turn order for players.
	//The distance of each player from the antenna determines his turn order in each rount.
	//Player with the minimum distance[ from the antenna will have the first turn in that round.
	//If there is a tie, player number will break it, for example if player 1 & 2 are in the same cell and they have the same distance from the antenna, player 1 will play first in that round.
	// 3- After deciding the turn of player Print a message indicating which player will play first example: "Player 1 will play first"

	// abdallah saad :)
    // Print message and wait for mouse click

    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("The antenna will decide the turn of players. Click to continue");
	int x;
	int y;
    pIn->GetPointClicked(x,y);
    pOut->ClearStatusBar(); // delete massege

    CellPosition antennaPos = position; // position of antena 
    CellPosition Firstplayer = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition(); // Get player 1 position
    CellPosition Secondplayer = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition(); // Get player 2 position


		int distanceFirstPlayer = abs(antennaPos.VCell() - Firstplayer.VCell()) + abs(antennaPos.HCell() - Firstplayer.HCell()); // calculate distand of p 1
	    int distanceSecondPlayer = abs(antennaPos.VCell() - Secondplayer.VCell()) + abs(antennaPos.HCell() - Secondplayer.HCell());// calculate distand of p 2
	
		int currentPlayer; // Variable to store the current player
		if (distanceFirstPlayer < distanceSecondPlayer) {
			currentPlayer = 0; // Player 1 is closer
		}
		else if (distanceFirstPlayer > distanceSecondPlayer) {
			currentPlayer = 1; // Player 2 is closer
		}
		else {
			currentPlayer = 0; // Player 1 plays first by default ( equal condition ) 
		}

		// Update the turn order in the grid
		pGrid->SetCurrentPlayer(currentPlayer);
}

Antenna::~Antenna()
{
}


