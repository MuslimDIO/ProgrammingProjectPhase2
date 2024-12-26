
/**
 * @file saveGridAction.cpp
 * @brief Implementation of the SaveGrid action for saving the grid state to a file.
 * @author Ibrahim Mohsen
 */

#include "saveGridAction.h"
#include "Grid.h"
#include "GameObject.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
 * @brief Reads the parameters required for the save action.
 * Prompts the user to enter a file name to save the grid.
 */
void SaveGrid::ReadActionParameters()
{
  Grid *pGrid = pManager->GetGrid();
  Output *pOut = pGrid->GetOutput();
  Input *pIn = pGrid->GetInput();
  pOut->PrintMessage("Enter the file name to save the grid");
  string fileName = pIn->GetSrting(pOut);
  _fileName = fileName;
  pOut->PrintMessage("SAVING GRID.......");
}

/**
 * @brief Executes the save action.
 * Reads the file name from the user, saves the grid state to the specified file, and notifies the user upon completion.
 */
void SaveGrid::Execute()
{
  ReadActionParameters();
  Grid *pGrid = pManager->GetGrid();
  ofstream l_outFile;
  l_outFile.open(_fileName + ".txt", ios::out);

  for (uint8_t i = 0; i <= ROTATING_GEAR; i++)
  {
    pGrid->SaveAll(l_outFile, (GameObject_Type)i);
  }

  l_outFile.close();

  Output *pOut = pGrid->GetOutput();
  pOut->PrintMessage("Grid saved successfully");
}

/**
 * @brief Constructor for the SaveGrid action.
 * @param pApp Pointer to the application manager.
 */
SaveGrid::SaveGrid(ApplicationManager *pApp) : Action(pApp)
{
}
SaveGrid::~SaveGrid()
{
}