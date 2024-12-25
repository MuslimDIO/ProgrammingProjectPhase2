#include "UseConsumable.h"
#include "ApplicationManager.h"

UseConsumable::UseConsumable(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}




void UseConsumable::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* pPlayer = pGrid->GetCurrentPlayer();

	pOut->PrintMessage("Would you like to use the 1. ToolKit or 2. Hacking Device");
	pOut->PrintMessage("Enter the type of consumable: tool kit (0) or hack device (1) ");
}



void UseConsumable::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* pPlayer = pGrid->GetCurrentPlayer();
	ReadActionParameters();

	int input = pIn->GetInteger(pOut);

	bool toolK = pPlayer->getToolKit();

	bool hackD = pPlayer->getHackDevice();
	

	bool condition = false; 

	if (input == 0 && toolK) {
		pPlayer->setHealth(pPlayer->getHealth() + 2); //repairs the robot
		pPlayer->hasToolKit(false); //removes the tool kit
		pOut->PrintMessage("You have used the Tool Kit");
		condition = true;
	}
	if (toolK == 1 && hackD) {
		pGrid->AdvanceCurrentPlayer(); //switches to opponent

		pPlayer = pGrid->GetCurrentPlayer(); //sets the player pointer to the new player
		pPlayer->setHacked(true); //hacks the player
		pPlayer->hasHackDevice(false); //removes the hack device
		pOut->PrintMessage("You have used the Hack Device");
		condition = true;
	}
	if (condition == false) {
		pOut->PrintMessage("Consumable not found.");
	}
}
UseConsumable::~UseConsumable() {

}