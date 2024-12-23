
/**
 * @file saveGridAction.h
 * @brief Header file for the SaveGrid action class.
 *
 * This file contains the declaration of the SaveGrid class, which is responsible
 * for saving the current grid state to a file.
 * @author Ibrahim Mohsen
 */

#ifndef _SAVE_GRID_H
#define _SAVE_GRID_H

#include "Action.h"

/**
 * @class SaveGrid
 * @brief A class to handle the action of saving the grid.
 *
 * The SaveGrid class inherits from the Action class and provides functionality
 * to save the current grid state to a specified file.
 */
class SaveGrid : public Action
{
    string _fileName; ///< The name of the file to save the grid to.

public:
    /**
     * @brief Constructor for the SaveGrid class.
     * @param pApp Pointer to the ApplicationManager.
     */
    SaveGrid(ApplicationManager *pApp);

    /**
     * @brief Destructor for the SaveGrid class.
     */
    ~SaveGrid();

    /**
     * @brief Reads the parameters required for the action.
     *
     * This function reads the parameters needed to execute the save action,
     * such as the file name.
     */
    virtual void ReadActionParameters();

    /**
     * @brief Executes the save action.
     *
     * This function performs the action of saving the current grid state to
     * the specified file.
     */
    virtual void Execute();
};

#endif // _SAVE_GRID_H