#include "Workshop.h"
#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;

Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition,WORKSHOP)
{

}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}
void Workshop::Apply(Grid* pGrid, Player* pPlayer)
{
    // Display options to the player
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();
    int choice;

   // do
   // {
        pOut->PrintMessage("You have entered a workshop! Choose an option:\n"
            "1. Repair Robot\n"
            "2. Equip Double Laser\n"
            "3. Activate Extended Memory\n"
            "4. Collect Toolkit\n"
            "5. Collect Hack Device\n"
            "6. Exit");

        choice = pIn->GetInteger(pOut);

        do
        {
            if (choice < 1 || choice > 6)
            {
                pOut->PrintMessage("Invalid choice. Please choose a valid number between 1 and 6.");
                choice = pIn->GetInteger(pOut);
            }
            else
            {
                break;
            }
        } while (true);


      

        // Handle valid choices and exit the workshop after processing
        switch (choice)
        {
        case 1: // Repair Robot
            if (pPlayer->getHealth() < 10) // Assuming max health is 10
            {
                pPlayer->setHealth(10);
                pOut->PrintMessage("Robot repaired successfully!");
            }
            else
            {
                pOut->PrintMessage("Your robot is already at full health!");
            }
            break;

        case 2: // Equip Double Laser
            pPlayer->setLaserType("Double Laser");
            pOut->PrintMessage("Double Laser equipped successfully!");
            break;

        case 3: // Activate Extended Memory
            pPlayer->EnableExtendedMemory();
            pOut->PrintMessage("Extended Memory activated successfully!");
            break;

        case 4: // Collect Toolkit
            if (pPlayer->getConsumableCount() < MAX_CONSUMABLES)
            {
                pPlayer->hasToolKit("Toolkit");
                pOut->PrintMessage("Toolkit collected successfully!");
            }
            else
            {
                pOut->PrintMessage("Cannot add Toolkit, inventory is full!");
            }
            break;

        case 5: // Collect Hack Device
            if (pPlayer->getConsumableCount() < MAX_CONSUMABLES)
            {
                pPlayer->hasHackDevice("Hack Device");
                pOut->PrintMessage("Hack Device collected successfully!");
            }
            else
            {
                pOut->PrintMessage("Cannot add Hack Device, inventory is full!");
            }
            break;

        case 6: // Exit
            pOut->PrintMessage("Exiting workshop.");
            break;
        }

        // Break out of the loop after processing a valid choice
       // break;

    //} while (true); // Keep looping only for invalid inputs
}
#if 0 
void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
    // Display options to the player
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("You have entered a workshop! Choose an option:\n1. Repair Robot\n2. Equip Double Laser\n3. Activate Extended Memory\n4. Collect Toolkit\n5. Collect Hack Device\n6. Exit");
    int choice = pIn->GetInteger(pOut);
    
    while (true)
    {
        if (choice < 1 || choice > 6)
        {
            pOut->PrintMessage("Invalid choice. You chose an invalid number. Please retry.");
            continue; // Re-prompt the player
        }
        else
            break;
            return;
        
    }
        switch (choice)
        {
        case 1: // Repair Robot
            if (pPlayer->getHealth() < 10) // Assuming max health is 10
            {
                pPlayer->setHealth(10);
                pOut->PrintMessage("Robot repaired successfully!");
            }
            else
            {
                pOut->PrintMessage("Your robot is already at full health!");
            }
            break;

        case 2: // Equip Double Laser
            pPlayer->setLaserType("Double Laser");
            pOut->PrintMessage("Double Laser equipped successfully!");
            break;

        case 3: // Activate Extended Memory
            pPlayer->EnableExtendedMemory();
            pOut->PrintMessage("Extended Memory activated successfully!");
            break;

        case 4: // Collect Toolkit
            if (pPlayer->getConsumableCount() < MAX_CONSUMABLES)
            {
                pPlayer->hasToolKit("Toolkit");
                pOut->PrintMessage("Toolkit collected successfully!");
            }
            else
            {
                pOut->PrintMessage("Toolkit can not be added!");
            }
            break;

        case 5: // Collect Hack Device
            if (pPlayer->getConsumableCount() < MAX_CONSUMABLES)
            {
                pPlayer->hasHackDevice("Hack Device");
                pOut->PrintMessage("Hack Device collected successfully!");
            }
            else
            {
                pOut->PrintMessage("Toolkit can not be added!");
            }
            break;

        case 6: // Exit
            pOut->PrintMessage("Exiting workshop.");
            break;

        }
    
}
#endif 
Workshop::~Workshop()
{
}
void Workshop::Save(ofstream &OutFile, GameObject_Type type)
{
	if (type == WORKSHOP)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << endl;
	}
}
void Workshop::Load(ifstream &Infile, GameObject_Type type)
{
	if (type == WORKSHOP)
	{
		int cellNum;
		Infile >> cellNum; // Read the cell number
		CellPosition cellPos = GetPosition().GetCellPositionFromNum(cellNum);
		position = cellPos;
	}
}