#include "ApplicationManager.h"

#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "SaveGridAction.h"
#include "LoadGridAction.h"
#include "switchToPlayModeAction.h"
#include"NewGameAction.h"
#include "SwitchToDesignModeAction.h"
#include "AddWaterPitAction.h"
#include "AddDangerZoneAction.h"
#include "AddWorkshopAction.h"
#include "AddAntennaAction.h"
#include "SelectCommandAction.h"
#include "RebootAndRepair.h"
#include "ExecuteCommandAction.h"
#include "CopyAction.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}


////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_BELT:
		pAct = new AddBeltAction(this);
		break;

	case ADD_ROTATINGGEAR:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;
	case SET_FLAG_CELL:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;

	case ADD_ANTENNA:
		// create an object of AddAntennaAction here
		pAct = new AddAntennaAction(this);
		break;

	case COPY:
		// create an object of CopyAction here
		pAct = new CopyAction(this);
		break;

	case NEW_GAME:
		pAct = new NewGameAction(this);
		break;

	case REBOOT_REPAIR:
		pAct = new RebootAndRepair(this);
		break;


	case ADD_WATER_PIT:
		// create an object of AddWaterPitAction here
		pAct = new AddWaterpitAction(this);
		break;

	case ADD_DANGER_ZONE:
		// create an object of AddDangerZoneAction here
		 pAct = new AddDangerZoneAction(this);
		break;

	case ADD_WORKSHOP:
		// create an object of AddWorkshopAction here
		 pAct = new AddWorkshopAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:					//TODO:
		pAct = new switchToPlayModeAction(this); // temporary till you made its action class (CHANGE THIS LATTER)
		break;
    case SAVE_GRID:
		pAct = new SaveGrid(this);
		break;
	case LOAD_GRID:
		pAct = new LoadGridAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new SwitchToDesignModeAction(this);
		break;
   case SELECT_COMMAND :
    pAct = new SelectCommandAction(this);
	break;
   case EXECUTE_COMMANDS:
	   pAct = new ExecuteCommandAction(this);
	   break;
		

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
