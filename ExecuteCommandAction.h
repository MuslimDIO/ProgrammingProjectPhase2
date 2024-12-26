
/**
 * @file ExecuteCommandAction.h
 * @brief Header file for the ExecuteCommandAction class.
 *
 * This file contains the definition of the ExecuteCommandAction class,
 * which is responsible for executing saved commands for the current player
 * in the game. The class inherits from the Action class and interacts with
 * various other classes such as Grid, Input, Output, and Player to perform
 * its functionality.
 * @author Omar Walid (Team Leader)
 */
#include "Action.h"
/**
 * @class ExecuteCommandAction
 * @brief A class to execute saved commands for the current player.
 *
 * This class inherits from the Action class and is used to execute
 * commands that have been saved by the current player. It interacts
 * with the Grid, Input, Output, and Player classes to perform its
 * functionality.
 */
class ExecuteCommandAction : public Action
{
public:
    ExecuteCommandAction(ApplicationManager *pApp);

    virtual ~ExecuteCommandAction();

    /**
     * @brief Reads the parameters required for the action.
     *
     * This function reads the necessary parameters for executing the action
     * from the input and output interfaces.
     */
    virtual void ReadActionParameters();
    /**
     * @brief Executes the saved command for the current player.
     *
     * This function performs the following steps:
     * - Reads the action parameters.
     * - Retrieves the current player and their saved commands.
     * - Executes the saved commands.
     * - Clears the saved commands.
     * - Generates available commands for the current player.
     * - Updates the game interface.
     * - Advances to the next player.
     * - Generates available commands for the new current player.
     * - Updates the commands bar in the game interface.
     */
    virtual void Execute();
};
