
#include "Player.h"
#include "Grid.h"
#include "Output.h"
#include <stdlib.h>
#include "GameObject.h"
#include <random>

Player::Player(Cell *pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT), canMove(true)
{
	this->pCell = pCell;
	lasertype = "default";
	toolKit = false;
	hackDevice = false;
	isHacked = false;
	canMove = true;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::EnableExtendedMemory()
{
	
}
void Player::SetCell(Cell *cell)
{
	pCell = cell;
}

Cell *Player::GetCell() const
{
	return pCell;
}

void Player::setHealth(int h)
{
	if (h < 0)
	{
		this->health = 0;
	}
	else if (h > 10)
	{
		this->health = 10;
	}
	else
	{
		this->health = h;
	}
}

int Player::getHealth()
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
	setCanMove(!isHacked);
}

bool Player::getHacked()
{
	return isHacked;
}

void Player::hasToolKit(bool t)
{
	toolKit = t;
}

void Player::hasHackDevice(bool h)
{
	hackDevice = h;
}

bool Player::getToolKit() const
{
	return toolKit;
}

bool Player::getHackDevice() const
{
	return hackDevice;
}

void Player::incrementConsumableCount()
{
	if (consumableCount < MAX_CONSUMABLES)
	{
		consumableCount++;
	}
}

void Player::decrementConsumableCount()
{
	if (consumableCount > 0)
	{
		consumableCount--;
	}
}

int Player::getConsumableCount() const
{
	return consumableCount;
}


void Player::setReachedFlag(bool flag)
{
	hasWon = flag;
}

#if 0
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

void Player::Draw(Output *pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor, currDirection);

	/// TODO: use the appropriate output function to draw the player with "playerColor"
}

void Player::ClearDrawing(Output *pOut) const
{
	/// TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;

	if (pCell->HasWaterPit())
	{
		cellColor = UI.CellColor_WaterPit;
	}
	else if (pCell->HasDangerZone())
	{
		cellColor = UI.CellColor_DangerZone;
	}

	/// TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	//pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor, currDirection);
	pOut->DrawCell(pCell->GetCellPosition(),cellColor);
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, Command moveCommands[])
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (!getCanMove()) {
		pOut->PrintMessage("You can't move this turn.");
		return;
	}

	if (pGrid->GetEndGame()) {
		pOut->PrintMessage("Game has ended. Click anywhere to continue.");
		return;
	}

	CellPosition currentPosition = pCell->GetCellPosition();
	CellPosition destination = currentPosition;



	for (int i = 0; i < 6; i++) {

		switch (moveCommands[i]) {
		case NO_COMMAND:
			continue; // Skip if no command
		case MOVE_FORWARD_ONE_STEP:
			destination.AddCellNum(1, currDirection);
			break;
		case MOVE_FORWARD_TWO_STEPS:
			destination.AddCellNum(2, currDirection);
			break;
		case MOVE_FORWARD_THREE_STEPS:
			destination.AddCellNum(3, currDirection);
			break;
		case MOVE_BACKWARD_ONE_STEP:
			destination.AddCellNum(-1, currDirection);
			break;
		case MOVE_BACKWARD_TWO_STEPS:
			destination.AddCellNum(-2, currDirection);
			break;
		case MOVE_BACKWARD_THREE_STEPS:
			destination.AddCellNum(-3, currDirection);
			break;
		case ROTATE_RIGHT:
			currDirection = static_cast<Direction>((currDirection + 1) % 4);
			break;
		case ROTATE_LEFT:
			currDirection = static_cast<Direction>((currDirection + 3) % 4);
			break;
		default:
			pOut->PrintMessage("Invalid move command.");
			continue;
		}

		if (!destination.IsValidCell()) {
			pOut->PrintMessage("Invalid move. Cannot move outside the grid.");
			return;
		}


		pGrid->UpdatePlayerCell(this, destination);

		pOut->PrintMessage("Click anywhere to execute the next command...");
		int x, y;
		pIn->GetPointClicked(x, y);

		pOut->ClearStatusBar();

		
		}

		GameObject* pObj = pCell->GetGameObject();
		if (pObj != nullptr) {
			pObj->Apply(pGrid, this);
		}

		if (hasWon == true) {
			pOut->PrintMessage("Player " + std::to_string(playerNum) + " wins!");
			EXIT;
		}

		pGrid->playerFinishedTurn();

		if (pGrid->AreAllPlayersReady()) {
			pGrid->ShootingPhase(); // Trigger the shooting phase
			pGrid->ResetTurnTracker(); // Reset for the next round
	    }

		

}
		/// TODO: Implement this function using the guidelines mentioned below

		// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
		//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
		//		After executing all the 5 saved commands, the game object effect at the final destination cell will
		//		be applied.
		//
		// - Use the CellPosition class to help you calculate the destination cell using the current cell
		// - Use the Grid class to update pCell
		// - Don't forget to apply game objects at the final destination cell and check for game ending

void Player::ShootingPhase(Grid* pGrid, Player* opponent) {
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	CellPosition myPosition = pCell->GetCellPosition();
	CellPosition opponentPosition = opponent->GetCell()->GetCellPosition();

	bool canShoot = false;
	if (currDirection == UP && myPosition.HCell() == opponentPosition.HCell() && myPosition.VCell() > opponentPosition.VCell()) {
		canShoot = true;
	}
	else if (currDirection == DOWN && myPosition.HCell() == opponentPosition.HCell() && myPosition.VCell() < opponentPosition.VCell()) {
		canShoot = true;
	}
	else if (currDirection == RIGHT && myPosition.VCell() == opponentPosition.VCell() && myPosition.HCell() < opponentPosition.HCell()) {
		canShoot = true;
	}
	else if (currDirection == LEFT && myPosition.VCell() == opponentPosition.VCell() && myPosition.HCell() > opponentPosition.HCell()) {
		canShoot = true;
	}

	if (canShoot) {
		int damage =  1; 
		opponent->SetHealth(opponent->GetHealth() - damage); 

		pOut->PrintMessage("Player " + std::to_string(playerNum) + " hit Player " + std::to_string(opponent->playerNum) + "! Click to continue.");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}
}




void Player::Restart()
{
	SetHealth(10);
	setCanMove(true);
	setHacked(false);
	toolKit = false;
	hackDevice = false;
	lasertype = "default";
	currDirection = RIGHT;
	for(int i =0; i<6;i++)
	{
		_SavedCommands[i] = NO_COMMAND;
	}
	for (int i = 0; i < COMMANDS_COUNT; i++)
	{
		_AvailableCommands[i] = NO_COMMAND;
	}
}

void Player::AppendPlayerInfo(string &playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";
}

void Player::Rotate(bool isClockWise, Output *ptr2_Out)
{
	switch (currDirection)
	{
	case UP:
		currDirection = isClockWise ? RIGHT : LEFT;

		break;
	case RIGHT:
		currDirection = isClockWise ? DOWN : UP;
		break;
	case DOWN:
		currDirection = isClockWise ? LEFT : RIGHT;
		break;
	case LEFT:
		currDirection = isClockWise ? UP : DOWN;
		break;
	}

	Draw(ptr2_Out);
}
/**
 * @brief Generates a list of available commands for the player based on their current health.
 * 
 * This function generates a random set of commands that the player can execute. The number of commands
 * generated is based on the player's current health, with a minimum of 5 commands. The commands are stored
 * in the _AvailableCommands array.
 * 
 * @param a_size Reference to an integer that will be set to the number of available commands generated.
 * @return Command* Pointer to the array of available commands.
 * @author Ibrahim Mohsen
 */
Command *Player ::GenerateAvailableCommands(int &a_size)
{

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, ((int)COMMANDS_COUNT - 3));

	int l_loopMax = GetHealth() >= 5 ? GetHealth() : 5;
	a_size = l_loopMax;
	_availableCommandsSize= l_loopMax;
	for (int i = 0; i < l_loopMax; i++)
	{
		int randomValue = distrib(gen);
		_AvailableCommands[i] = (Command)randomValue;

	}
	for (int i = l_loopMax; i < COMMANDS_COUNT; i++)
	{
		
		_AvailableCommands[i] = NO_COMMAND;

	}
	return _AvailableCommands;
}
/**
 * @brief Retrieves the saved commands for the player.
 * 
 * This function returns a pointer to the array of saved commands for the player.
 * It also sets the size of the array to the provided reference parameter.
 * 
 * @param a_size Reference to an integer where the size of the saved commands array will be stored.
 * @return Command* Pointer to the array of saved commands.
 */
Command * Player::GetSavedCommands(int & a_size) 
{  
	  a_size = 5;
	return _SavedCommands;
}


/**
 * @brief Saves a command to the player's saved commands list.
 * 
 * This function attempts to save a command, identified by its index, 
 * to the player's list of saved commands. It searches for the first 
 * available slot (indicated by NO_COMMAND) and saves the command there.
 * 
 * @param a_commandIndex The index of the command to be saved from the available commands list.
 * @return true if the command was successfully saved to an available slot.
 * @return false if there are no available slots to save the command.
 * @author Ibrahim Mohsen
 */
bool  Player::SaveCommand(int  a_commandIndex)
{
	for (int i = 0; i < 5; i++)
	{
		if (_SavedCommands[i] == NO_COMMAND)
		{
			_SavedCommands[i] = _AvailableCommands[a_commandIndex];
			return true ;
		}
	}
	return false;
}
/**
 * @brief Retrieves the available commands for the player.
 * 
 * This function returns a pointer to an array of Command objects that are available to the player.
 * It also sets the size of the available commands array through the reference parameter.
 * 
 * @param a_size Reference to an integer where the size of the available commands array will be stored.
 * @return Command* Pointer to the array of available Command objects.
 * @author Ibrahim Mohsen
 */
Command * Player::GetAvailableCommands(int & a_size)
{
	a_size = _availableCommandsSize;
	return _AvailableCommands;
}

