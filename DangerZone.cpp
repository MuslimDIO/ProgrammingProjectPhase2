#include "DangerZone.h"
#include <iostream>
#include <fstream>
#include "Player.h"

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

	// abdallah saad :)
   
    Output* pOut = pGrid->GetOutput(); // access the output 
    Input* pIn = pGrid->GetInput();   // access the input

    pOut->PrintMessage("You have reached a danger zone. Click to continue"); // print massage
    int x, y;
    pIn->GetPointClicked(x, y); // Wait for user input
    pOut->ClearStatusBar();    // delete the massage 

   // Apply the effect

     
    int currentHealth = pPlayer->GetHealth();
    int newHealth = currentHealth - 1; // Reduce health by 1
    
    pPlayer->SetHealth(newHealth);

    // Step 3: Check if the player's health is zero
    if (newHealth == 0) {
        pOut->PrintMessage("Your health has reached zero. Game over. Click to continue");
        pGrid->SetEndGame(true); // End the game
        pIn->GetPointClicked(x, y);
        pOut->ClearStatusBar();
        return; // Exit the function to prevent further actions
    }

    // Update the grid display with the player's new health
    pGrid->UpdateInterface();

    // Notify the player of their new health
    pOut->PrintMessage("Your health is now: " + std::to_string(newHealth) + ". Click to continue...");
    pIn->GetPointClicked(x, y);
    pOut->ClearStatusBar();
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