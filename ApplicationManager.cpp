#include "ApplicationManager.h"
#include "Switch_to_DesignMode.h"
#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include "InputDiceValue.h"
#include "NewGame.h"
#include "SaveGridAction.h"
#include "OpenGridAction.h"
#include "DeleteGameObject.h"
#include"CopyCardAction.h"
#include"CutCardAction.h"
#include"PasteCardAction.h"
#include"Snake.h"
#include "Switch_to_PlayMode.h"
#include"EditCard.h"

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

Grid* ApplicationManager::GetGrid() const
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
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;

	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;
	case Copy:
		pAct = new CopyCardAction(this);
		break;
	case Delete:
		pAct = new DeleteGameObject(this);
		break;

	case Cut:
		pAct = new CutCardAction(this);
		break;

	case Paste:
		pAct = new PasteCardAction(this);
		break;
	case Save:
		pAct = new SaveGridAction(this);
		break;
	case Open:
		pAct = new  OpenGridAction(this);

	case EXIT:
		break;

	case TO_PLAY_MODE:
		pAct = new Switch_to_PlayMode(this);
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case TO_DESIGN_MODE:
		pAct = new Switch_to_DesignMode(this);
		break;

	case Edit:
		pAct= new EditCard(this);
		break;

	
		///TODO: Add a case for EACH Action type in the Design mode or Play mode

	case INPUT_DICE_VALUE:
		// create an object of RollDiceAction here
		pAct = new InputDiceValue(this);
		break;
	case NEW_GAME:
		pAct = new NewGame(this);
		break;


	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
