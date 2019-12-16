#include "RollDiceAction.h"
#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
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
		
		// 2- Generate a random number from 1 to 6 --> This step is done for you
		srand((int)time(NULL)); // time is for different seed each run
		int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

		// 3- Get the "current" player from pGrid
		Player* pPlayer = pGrid->GetCurrentPlayer();
		// 4- Move the currentPlayer using function Move of class player
		Cell* pCell = pPlayer->GetCell();
		CellPosition cellpositin = pCell->GetCellPosition();
		int cellnum = cellpositin.GetCellNum();
		if (cellnum + diceNumber >= 99)
		{
			
			pGrid->GetOutput()->PrintMessage("WINNER...WINNER Chicken Dinner!!!!..click to continue  ");
			pGrid->GetInput()->GetCellClicked();
			pGrid->SetEndGame(true);
			pGrid->GetOutput()->ClearStatusBar();
			pGrid->GetOutput()->PrintMessage("Do you want to paly again ? press[y/n]");
			if (pGrid->GetInput()->GetSrting(pGrid->GetOutput()) == "y")
			{
				pManager->ExecuteAction(NEW_GAME);
			}
			else
			{
				pManager->ExecuteAction(EXIT);
			}
			
		}
		else
		{
			pPlayer->Move(pGrid, diceNumber);
			// 5- Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();
			// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
		}
	}
}

RollDiceAction::~RollDiceAction()
{
}