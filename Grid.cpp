#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Belt.h"
#include "Player.h"
#include "Flag.h"
#include "WaterPit.h"
#include "DangerZone.h"
#include "Workshop.h"
#include "Antenna.h"
#include "RotatingGear.h"
#include <fstream>
#include <iostream>
extern int flagAdded;
extern int AntennaAdded;
using namespace std;
class CellPosition;
Grid::Grid(Input *pIn, Output *pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut);										  // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;

	//intialize players ready to shoot with 0
	playerShooting = 0; 
}

// ========= Adding or Removing GameObjects to Cells =========

bool Grid::AddObjectToCell(GameObject *pNewObject) // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject *pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

GameObject* Grid::GetGameObject(const CellPosition& pos) const
{
	if (pos.IsValidCell()) // Check if valid position
	{
		return CellList[pos.VCell()][pos.HCell()]->GetGameObject();
	}
	return NULL; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
bool Grid::RemoveObjectFromCell(const CellPosition &pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed
		if (CellList[pos.VCell()][pos.HCell()]->GetGameObject() == NULL) {
			return false;
		}

        CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
	else {
		return false;
	}
	return true;
}

void Grid::RemoveAllObjects()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CellPosition pos(i, j);
			RemoveObjectFromCell(pos);
		}
	}
}

void Grid::RestartAllPlayers()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		CellPosition start(0, 0);
		PlayerList[i]->Restart();
		UpdatePlayerCell(PlayerList[i], start);
	}
	ResetCurrentPlayerNum();
}

void Grid::ResetCurrentPlayerNum()
{
	currPlayerNumber = 0;
}

void Grid::UpdatePlayerCell(Player *player, const CellPosition &newPosition)
{
	// Clear the player's triangle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell *newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's triangle on the new cell position
	player->Draw(pOut);
}

// ========= Setters and Getters Functions =========

void Grid::SetCurrentPlayer(int playerNumber)
{
	if (playerNumber >= 0 && playerNumber < MaxPlayerCount)
	{
		currPlayerNumber = playerNumber;
	}
}

Input *Grid::GetInput() const
{
	return pIn;
}

Output *Grid::GetOutput() const
{
	return pOut;
}
/**
 * @author Ibrahim Mohsen
 **/
bool Grid:: SetClipboard(CellPosition *a_pos) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = CellList[a_pos->VCell()][a_pos->HCell()]->GetGameObject();

	return Clipboard ? true : false;
}

GameObject *Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========

Player *Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Belt *Grid::GetNextBelt(const CellPosition &position)
{

	int startH = position.HCell();				// represents the start hCell in the current row to search for the belt in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasBelt())
			{
				return CellList[i][j]->HasBelt();
			}
			/// TODO: Check if CellList[i][j] has a belt, if yes return it
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

// ========= Shooting Phase Functions =========

void Grid::playerFinishedTurn() //increment the number of players that finished their turn.
{
	playerShooting++;
}

bool Grid::AreAllPlayersReady() const //check if all players finished their turn.
{
	return playerShooting == MaxPlayerCount;
}

void Grid::ResetTurnTracker() //reset the number of players that finished their turn.
{
	playerShooting = 0;
}

void Grid::ShootingPhase() //the shooting phase of the game.
{
	for (int i = 0; i < MaxPlayerCount; i++) {
		Player* currentPlayer = PlayerList[i];
		if (currentPlayer != nullptr) {
			for (int j = 0; j < MaxPlayerCount; j++) {
				if (i == j) continue;

				Player* opponent = PlayerList[j];
				if (opponent != nullptr) {
					currentPlayer->ShootingPhase(this, opponent);
				}
			}
		}
	}

}

// ========= User Interface Functions =========

void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without waterpits or dangerzone
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrWaterPitOrDangerZone(pOut);
			}
		}

		// 2- Draw other game objects(excluding waterpit and dangerzone)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawGameObject(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1)					  // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cgame objects do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::SaveAll(ofstream &a_OutFile, GameObject_Type a_type)
{
	int l_objCount = 0;
	// Save the GameObject parameters to the file
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			GameObject *ptr2_GObj = CellList[i][j]->GetGameObject();
			if (ptr2_GObj != NULL && ptr2_GObj->getObjType() == a_type)
			{
				l_objCount++; // increment the count of the objects of the same type
			}
		}
	}
	a_OutFile << l_objCount << endl;

	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			GameObject *ptr2_GObj = CellList[i][j]->GetGameObject();
			if (ptr2_GObj && ptr2_GObj->getObjType() == a_type)
			{
				ptr2_GObj->Save(a_OutFile, a_type); // Saves the GameObject parameters to the file
			}
		}
	}
}

void Grid::LoadAll(ifstream &a_InFile, GameObject_Type a_type)
{
	int l_objCount = 0;
	a_InFile >> l_objCount;
	for (int i = 0; i < l_objCount; i++)
	{
		GameObject *ptr2_GObj = NULL;
		switch (a_type)
		{
		case FLAG:
			ptr2_GObj = new Flag(CellPosition(0, 0));
			flagAdded++;
			break;
		case WATERPIT:
			ptr2_GObj = new WaterPit(CellPosition(0, 0));
			break;
		case DANGERZONE:
			ptr2_GObj = new DangerZone(CellPosition(0, 0));
			break;
		case BELT:
			ptr2_GObj = new Belt(CellPosition(0, 0), CellPosition(0, 0));
			break;
		case WORKSHOP:
			ptr2_GObj = new Workshop(CellPosition(0, 0));
			break;
		case ANTENNA:
			ptr2_GObj = new Antenna(CellPosition(0, 0));
			AntennaAdded++;
			break;
		case ROTATING_GEAR:
			ptr2_GObj = new RotatingGear(CellPosition(0, 0));
			break;
		}
		ptr2_GObj->Load(a_InFile, a_type);
		AddObjectToCell(ptr2_GObj);
	}
}
Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}