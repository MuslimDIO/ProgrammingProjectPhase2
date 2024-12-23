#include "Player.h"
#include "Grid.h"
#include "Output.h"

#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT), canMove(true)
{
	this->pCell = pCell;
	lasertype = "default";
	consumableCount = 0;
	isHacked = false;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetHealth(int h)
{
	if (h < 0) {
		this->health = 0;
	}
	else if (h > 10) {
		this->health = 10;
	}
	else {
		this->health = h;
	}
}

int Player::GetHealth()
{
	return this->health;
}

void Player::setLaserType(string l)
{
	lasertype = l;
}

string Player::getLaserType()
{
	return lasertype;
}

void Player::setCanMove(bool c)
{
	canMove = c;
}

bool Player::getCanMove()
{
	return canMove;
}



void Player::setHacked(bool h)
{
	isHacked = h;
}

bool Player::getHacked()
{
	return isHacked;
}


string Player::GetConsumables() const
{
	string consumables = "";
	for (int i = 0; i < consumableCount; i++)
	{
		consumables += ownedConsumables[i] + " ";
	}
	return consumables;
}


bool Player::AddConsumable(string consumable)
{
	if (consumableCount < MAX_CONSUMABLES)
	{
		ownedConsumables[consumableCount++] = consumable;

		return true;
	}
	return false;
}

int Player::GetConsumableCount() const
{
	return consumableCount;
}
#if 1
bool Player::UseConsumable(const string consumable, Output* pOut)
{
	for (int i = 0; i < consumableCount; i++)
	{
		if (ownedConsumables[i] == consumable)
		{
			if (ownedConsumables[i] == consumable) {
				// Apply consumable effects
				if (consumable == "Toolkit") {
					SetHealth(health + 2); // Restore health
					pOut->PrintMessage("Used Toolkit: Restored 2 health points.");
				}
				else if (consumable == "HackDevice") {
					// logic for the hack device ely ana mesh 3aref eh howa aslan
					setHacked(true); //5alas 3rfto bas 
					pOut->PrintMessage("Used Hack Device: Opponent is blocked this round.");
				}

				// Remove the consumable from the array
				for (int j = i; j < consumableCount - 1; ++j) {
					ownedConsumables[j] = ownedConsumables[j + 1];
				}
				ownedConsumables[--consumableCount] = ""; // Clear the last slot
				return true;
			}
		}
		pOut->PrintMessage("Consumable not available.");
		return false; // Consumable not found
	}
}
#endif
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor, currDirection);
	
		///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;

	if (pCell->HasWaterPit()) {
		cellColor = UI.CellColor_WaterPit;
	}
	else if (pCell->HasDangerZone()) {
		cellColor = UI.CellColor_DangerZone;
	}
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor, currDirection);
}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, Command moveCommands[])
{

	///TODO: Implement this function using the guidelines mentioned below

	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
	//		be applied.
	// 
	// - Use the CellPosition class to help you calculate the destination cell using the current cell
	// - Use the Grid class to update pCell
	// - Don't forget to apply game objects at the final destination cell and check for game ending

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";

}




