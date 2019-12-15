#include "NewGame.h"
#include "Grid.h"
#include "Player.h"
#include "Action.h"

NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGame::ReadActionParameters()
{


}

void NewGame::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	if (pGrid->GetEndGame())
	{
	}
	else
	{

		// -- If not ended, do the following --:

		// 3- Get the "current" player from pGrid
		for (int i = 0; i < 4; i++)
		{
			Player* pPlayer = pGrid->GetCurrentPlayer();
			// 4- Move the currentPlayer using function Move of class player

			//pPlayer->ClearDrawing(pOut);

			CellPosition cel(1);
			pGrid->UpdatePlayerCell(pPlayer, cel);

			//pPlayer->Draw(pOut);


			pPlayer->Set_turncount(0);
			pPlayer->SetWallet(100);
			// 5- Advance the current player number of pGrid
			pGrid->AdvanceCurrentPlayer();
		}
		pGrid->set_currplayernum(0);
		// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	}
}

NewGame::~NewGame()
{
}