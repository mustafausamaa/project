#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include"Snake.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

int Grid::get_currplayernum()
{
	return currPlayerNumber;
}

void Grid::set_currplayernum(int playernum)
{
	currPlayerNumber = playernum;
}

void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);
	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========
GameObject* Grid::getgameobject(CellPosition pos)const {
	return CellList[pos.VCell()][pos.HCell()]->GetGameObject();
}
void Grid::setClipboardFlag(int x) {
	ClipboardFlag = x;
}
int Grid::getClipboardFlag()const {
	return ClipboardFlag;
}

Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasLadder())
				return CellList[i][j]->HasLadder();

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}
Snake* Grid::GetNextSnake(const CellPosition& position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{

			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasSnake())
				return CellList[i][j]->HasSnake();
		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found

}


// ========= User Interface Functions =========


bool Grid::IsOverlapping(GameObject* newObj)const {

	bool z = 0;
	GameObject* original = NULL;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			if (CellList[i][j]->GetGameObject() != NULL && CellList[i][j]->GetGameObject() != newObj) {
				original = CellList[i][j]->GetGameObject();
				z = original->IsOverlapping(newObj);
				if (z == 1) {
					return 1;
				}
			}
		}
	}
	return 0;
}

void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

void Grid::SaveAll(ofstream& Output, GOType Type) const
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			GameObject* pGopject = CellList[i][j]->GetGameObject();
			if (pGopject != NULL)
				pGopject->Save(Output, Type);
		}
	}

}

void Grid::DeleteAll()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			GameObject* pGopject = CellList[i][j]->GetGameObject();
			if (pGopject != NULL)
				RemoveObjectFromCell(pGopject->GetPosition());
		}
	}
}

int Grid::numofladders()
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			Ladder* pLadder = CellList[i][j]->HasLadder();
			if (pLadder != NULL)
				count++;
		}
	}
	return count;
}
int Grid::numofSnakes()
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			Snake* pSnake = CellList[i][j]->HasSnake();
			if (pSnake != NULL)
				count++;
		}
	}
	return count;
}
int Grid::numofCards()
{
	int count = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // left to right
		{
			Card* pCard = CellList[i][j]->HasCard();
			if (pCard != NULL)
				count++;
		}
	}
	return count;
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}
void Grid::SpecialAttack_ICE()
{
	if (GetCurrentPlayer()->Get_prevent_used())
	{
		PrintErrorMessage("It's Same Attack Last Time Can't take it ...");
		return;
	}
	pOut->PrintMessage("Choose a player to prevent from rolling the next turn from 1-4");
	int pnum = pIn->GetInteger(pOut)-1;
	if (pnum == currPlayerNumber)
	{
		PrintErrorMessage("It's you who will affect Not my fault Sorry.. ");
		PlayerList[pnum]->set_prevented(true);
	}
	else
	{
		PlayerList[pnum]->set_prevented(true);
	}
}
void Grid::SpecialAttack_FIRE()
{
	if (GetCurrentPlayer()->Get_Fire_used())
	{
		PrintErrorMessage("It's Same Attack Last Time Can't take it ...");
		return;
	}
	pOut->PrintMessage("Choose a player to burn.. from 1-4");
	int pnum = pIn->GetInteger(pOut) - 1;
	if (pnum == currPlayerNumber)
	{
		PrintErrorMessage("It's you who will affect Not my fault Sorry.. ");
		PlayerList[pnum]->set_Fired(true);
	}
	else
	{
		PlayerList[pnum]->set_Fired(true);
	}
}
void Grid::SpecialAttack_POISON()
{
	if (GetCurrentPlayer()->Get_Poison_used())
	{
		PrintErrorMessage("It's Same Attack Last Time Can't take it ...");
		return;
	}
	pOut->PrintMessage("Choose a player to Poison.. from 1-4");
	int pnum = pIn->GetInteger(pOut) - 1;
	if (pnum == currPlayerNumber)
	{
		PrintErrorMessage("It's you who will affect Not my fault Sorry.. ");
		PlayerList[pnum]->set_Poisoned(true);
	}
	else
	{
		PlayerList[pnum]->set_Poisoned(true);
	}
}
void Grid::SpecialAttack_LIGHTNING(Player * pPlayer)
{
	if (GetCurrentPlayer()->Get_lightining_used())
	{
		PrintErrorMessage("It's Same Attack Last Time Can't take it ...");
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int wall = PlayerList[i]->GetWallet();
		PlayerList[i]->SetWallet((wall - 20));
	}
	pPlayer->set_Lightining_used(true);
}
