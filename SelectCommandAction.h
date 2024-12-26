/**
 * @file SelectCommandAction.h
 * @brief Header file for the SelectCommandAction class.
 *
 * This file contains the declaration of the SelectCommandAction class, which is responsible
 * for handling the selection of commands in the application.
 * @author Ibrahim Mohsen
 */

#ifndef _SELECTCOMMANDACTION_H
#define _SELECTCOMMANDACTION_H

#include "Action.h"

/**
 * @class SelectCommandAction
 * @brief A class to handle the action of selecting a command.
 *
 * The SelectCommandAction class inherits from the Action class and provides functionality
 * to read the parameters required for the selection action and execute the selection.
 */
class SelectCommandAction : public Action
{
public:
    /**
     * @brief Constructor for the SelectCommandAction class.
     * @param pApp Pointer to the application manager.
     */
    SelectCommandAction(ApplicationManager *pApp);

    /**
     * @brief Destructor for the SelectCommandAction class.
     */
    virtual ~SelectCommandAction();

    /**
     * @brief Reads the parameters required for the select command action.
     */
    virtual void ReadActionParameters();

    /**
     * @brief Executes the select command action.
     */
    virtual void Execute();
};

#endif