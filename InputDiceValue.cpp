#include "InputDiceValue.h"
#include "Grid.h"
#include "Player.h"
#include "Action.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{


}

void InputDiceValue::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();

	if (pGrid->GetEndGame())
	{
	}
	else
	{

		// -- If not ended, do the following --:

		pGrid->GetOutput()->PrintMessage("please enter a dice value between 1-6 : ");
		diceValue = (pGrid->GetInput())->GetInteger(pGrid->GetOutput());
		(pGrid->GetOutput())->ClearStatusBar();
		// 3- Get the "current" player from pGrid
		Player* pPlayer = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		pPlayer->Move(pGrid, diceValue);
		// 5- Advance the current player number of pGrid
		pGrid->AdvanceCurrentPlayer();
		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

InputDiceValue::~InputDiceValue()
{
}