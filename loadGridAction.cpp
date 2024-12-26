/**
 * @file loadGridAction.cpp
 * @brief Implementation of the LoadGridAction class for loading a grid from a file.
 *
 * This file contains the implementation of the LoadGridAction class, which is responsible
 * for loading a grid from a specified file. The class provides methods to read the necessary
 * parameters and execute the loading action, including reading game objects from the file
 * and adding them to the grid.
 *
 * The file to be loaded is expected to have a ".txt" extension.
 *
 * @author Ibrahim Mohsen
 *
 */
#include "loadGridAction.h"
#include "Grid.h"
#include "GameObject.h"
#include <fstream>
#include <iostream>
using namespace std;

LoadGridAction::LoadGridAction(ApplicationManager *pApp) : Action(pApp)
{
}
/**
 * @brief Reads the parameters required for the LoadGridAction.
 *
 * This function prompts the user to enter the file name from which the grid will be loaded.
 * It retrieves the file name from the user input and stores it in the _fileName member variable.
 * Additionally, it displays a message indicating that the grid is being loaded.
 */
void LoadGridAction::ReadActionParameters()
{
    Grid *pGrid = pManager->GetGrid();
    Output *pOut = pGrid->GetOutput();
    Input *pIn = pGrid->GetInput();
    pOut->PrintMessage("Enter the file name to load the grid");
    string a_fileName = pIn->GetSrting(pOut);
    _fileName = a_fileName;
    pOut->PrintMessage("LOADING GRID.......");
}

/**
 * @brief Executes the action of loading a grid from a file.
 *
 * This function reads the parameters required for the action, opens the specified file,
 * and loads all game objects into the grid from the file. After loading, it prints a
 * success message.
 *
 * @note The file to be loaded is expected to have a ".txt" extension.
 */
void LoadGridAction ::Execute()
{
    ReadActionParameters();

    Grid *pGrid = pManager->GetGrid();

    pGrid->RemoveAllObjects();

    pGrid->UpdateInterface();
    ifstream l_inFile;
    l_inFile.open(_fileName + ".txt", ios::in);

    // l_outFile<<"start file"<<endl;
    for (int i = 0; i <= ROTATING_GEAR; i++)
    {
        pGrid->LoadAll(l_inFile, (GameObject_Type)i);
    }
    // l_outFile<<"END file"<<endl;
    l_inFile.close();

    Output *pOut = pGrid->GetOutput();
    pOut->PrintMessage("Grid Loaded successfully");
}

LoadGridAction::~LoadGridAction()
{
}