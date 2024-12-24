
/**
 * @file switchToPlayModeAction.h
 * @brief Header file for the switchToPlayModeAction class.
 *
 * This file contains the declaration of the switchToPlayModeAction class, which is
 * responsible for handling the action of switching the application to play mode.
 * The class inherits from the Action base class and provides implementations for
 * reading action parameters and executing the action.
 * @author Ibrahim Mohsen
 */
#ifndef _SWITCH_TO_PLAY_MODE_ACTION_H
#define _SWITCH_TO_PLAY_MODE_ACTION_H
#include "Action.h"

enum Command;

class switchToPlayModeAction : public Action
{
public:
    /**
     * @brief Reads the parameters required for the action.
     *
     * This function is responsible for reading any parameters that are necessary
     * for executing the switch to play mode action.
     */
    virtual void ReadActionParameters();

    /**
     * @brief Executes the switch to play mode action.
     *
     * This function performs the necessary operations to switch the application
     * to play mode.
     */
    virtual void Execute();

    /**
     * @brief Constructor for switchToPlayModeAction.
     *
     * Initializes a new instance of the switchToPlayModeAction class.
     *
     * @param pApp Pointer to the ApplicationManager instance.
     */
    switchToPlayModeAction(ApplicationManager *pApp);

    /**
     * @brief Destructor for switchToPlayModeAction.
     *
     * Cleans up any resources used by the switchToPlayModeAction instance.
     */
    ~switchToPlayModeAction();
};

#endif // _SWITCH_TO_PLAY_MODE_ACTION_H