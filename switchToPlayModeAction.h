
#ifndef _SWITCH_TO_PLAY_MODE_ACTION_H
#define _SWITCH_TO_PLAY_MODE_ACTION_H
#include "Action.h"

enum Command;
/**
 * @class switchToPlayModeAction
 * @brief This class handles the action of switching the application to play mode.
 *
 * This class is responsible for reading the necessary parameters and executing
 * the action to switch the application from its current mode to play mode.
 * @author Ibrahim Mohsen
 */
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