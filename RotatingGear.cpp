
/**
 * @file RotatingGear.cpp
 * @brief Implementation of the RotatingGear class.
 * 
 * This file contains the implementation of the RotatingGear class, which represents a rotating gear
 * @author Abdullah Saad
 */

 /**
    * @class RotatingGear
    * @brief Represents a rotating gear object in the game.
    * 
    * The RotatingGear class is a type of GameObject that rotates the player when they land on it.
    */

/**
 * @brief Constructs a RotatingGear object with a specified position and default clockwise rotation.
 * @param gearposition The position of the rotating gear on the grid.
 */
 
 /**
    * @brief Constructs a RotatingGear object with a specified position and rotation direction.
    * @param gearposition The position of the rotating gear on the grid.
    * @param a_clockWise The direction of rotation (true for clockwise, false for counterclockwise).
    */

/**
 * @brief Draws the rotating gear on the grid.
 * @param pOut Pointer to the Output interface.
 */

/**
 * @brief Applies the effect of the rotating gear to the player.
 * @param pGrid Pointer to the Grid.
 * @param pPlayer Pointer to the Player.
 */

/**
 * @brief Gets the rotation direction of the rotating gear.
 * @return True if the rotation is clockwise, false otherwise.
 */

/**
 * @brief Sets the rotation direction of the rotating gear.
 * @param a_isClockWise The new rotation direction (true for clockwise, false for counterclockwise).
 */

/**
 * @brief Saves the state of the rotating gear to a file.
 * @param OutFile Reference to the output file stream.
 * @param type The type of the game object.
 */

/**
 * @brief Loads the state of the rotating gear from a file.
 * @param Infile Reference to the input file stream.
 * @param type The type of the game object.
 */

/**
 * @brief Destructor for the RotatingGear class.
 */
#include "RotatingGear.h"
#include <fstream>  
#include <iostream>
#include "Player.h"
using namespace std;



RotatingGear::RotatingGear(const CellPosition & gearposition) : GameObject(gearposition, ROTATING_GEAR)
{
	isClockWise = true;
}
RotatingGear::RotatingGear(const CellPosition & gearposition,bool a_clockWise) : GameObject(gearposition, ROTATING_GEAR)
{
	isClockWise = a_clockWise;
}

void RotatingGear::Draw(Output* pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	//2- Apply the roating gear's effect by rotating the player according to the direction

	// abdallah saad :) 

    
    // Step 1: Access the Output and Input interfaces
    Output* pOut = pGrid->GetOutput(); // Access the Output
    Input* pIn = pGrid->GetInput();   // Access the Input (maybe not important)

   
  

    #if 0
    while (!validCell) // making infint loop untill the user click valied cell
    {
        // Print a message based on the rotation 
        if (isClockWise)
        {
            pOut->PrintMessage("You have reached a rotating gear. You will rotate clockwise. Click on a valid cell to continue...");
        }
        else
        {
            pOut->PrintMessage("You have reached a rotating gear. You will rotate counterclockwise. Click on a valid cell to continue...");
        }

        
        pos = pIn->GetCellClicked(); // Wait for the player to click and get the CellPosition

        // Check if the cell is valid

        if (pos.IsValidCell())
        {
            validCell = true; // Exit the loop if the cell is valid
        }
        else
        {
            pOut->PrintMessage("Invalid cell position! Please try again.");
        }
    }
#endif 
    //  Apply the rotation effect to the player
    pPlayer->ClearDrawing(pOut);
    CellPosition currentPos = pGrid->GetCurrentPlayer()->GetCell()->GetCellPosition();
    pOut->DrawRotatingGear(currentPos,isClockWise);
    pPlayer->Rotate(isClockWise, pOut); // Rotate the player in the specified direction
   

    int x, y;
    pOut->PrintMessage("the player has been rotated succefly");
    pIn->GetPointClicked(x, y);
    pOut->ClearStatusBar();
}

bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}
void RotatingGear::setIsClockWise(bool a_isClockWise)
{
	isClockWise = a_isClockWise;
}
void RotatingGear::Save(ofstream & OutFile, GameObject_Type type)
{
	if (type == ROTATING_GEAR)
	{
		CellPosition cellPos = GetPosition();
		OutFile << cellPos.GetCellNum() << " " << isClockWise << endl;
	}
}
void RotatingGear::Load(ifstream &Infile, GameObject_Type type)
{
	if (type == ROTATING_GEAR)
	{
		int l_cellNum;
		bool l_clockwise;
		Infile >> l_cellNum >> l_clockwise; // Read the cell number
		CellPosition cellPos = GetPosition().GetCellPositionFromNum(l_cellNum);
		position = cellPos;
		isClockWise = l_clockwise;
	}
}	
RotatingGear::~RotatingGear()
{
}
