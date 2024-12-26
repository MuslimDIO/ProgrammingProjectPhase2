/**
 * @file loadGridAction.h
 * @brief Header file for the LoadGridAction class.
 *
 * This file contains the declaration of the LoadGridAction class, which is responsible for loading a grid from a file.
 * @author Ibrahim Mohsen
 */

#ifndef _LOADGRIDACTION_H
#define _LOADGRIDACTION_H
#include "Action.h"
#include <fstream>
#include <iostream>

using namespace std;
/**
 * @class LoadGridAction
 * @brief A class to handle the action of loading a grid from a file.
 *
 * This class provides functionality to read the filename from the user, execute the loading of the grid, and clean up resources.
 */
class LoadGridAction : public Action
{
    string _fileName;

public:
    /**
     * @brief Constructor for LoadGridAction.
     * @param pApp Pointer to the ApplicationManager.
     */
    LoadGridAction(ApplicationManager *pApp);

    /**
     * @brief Reads the parameters required for the LoadGridAction.
     *
     * This function prompts the user to enter the file name from which the grid will be loaded.
     * It retrieves the file name from the user input and stores it in the _fileName member variable.
     * Additionally, it displays a message indicating that the grid is being loaded.
     */
    virtual void ReadActionParameters();
    /**
     * @brief Executes the action of loading a grid from a file.
     *
     * This function reads the parameters required for the action, opens the specified file,
     * and loads all game objects into the grid from the file. After loading, it prints a
     * success message.
     *
     * @note The file to be loaded is expected to have a ".txt" extension.
     */
    virtual void Execute(); // Loads the Grid from a file

    virtual ~LoadGridAction(); // A Virtual Destructor
};

#endif