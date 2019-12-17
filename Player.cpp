#include "Player.h"
#include "Card.h"
#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	Roll = true;
	freeze = false;
	prevented = false;
	Fired = false;
	Poisoned = false;
	Poison_used = false;
	Fire_used = false;
	lightining_used = false;
	prevent_used = false;
	SpecialAttacks_Counter = 0;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::set_roll(bool roll)
{
	Roll = roll;
}
void Player::set_prevented(bool t)
{
	prevented = t;
}
void Player::set_Fired(bool t)
{
	Fired = t;
	punishperiod = 0;
}
void Player::set_Poisoned(bool t)
{
	Poisoned = t;
	punishperiod = 0;
}
void Player::set_Lightining_used(bool t)
{
	lightining_used = t;
	
}
void Player::setfreeze(bool f)
{
	freeze = f;
}


void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::Set_turncount(int count)
{
	turnCount = count;
}

void Player::SetWallet(int wallet)
{
	
	this->wallet = (wallet > 0 ? wallet:0);
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}
bool Player::Get_Fire_used()
{
	return Fire_used;
}
bool Player::Get_Poison_used()
{
	return Poison_used;
}
bool Player::Get_prevent_used()
{
	return prevent_used;
}
bool Player::Get_lightining_used()
{
	return lightining_used;
}
int Player::GetTurnCount() const
{
	return turnCount;
}

void Player::Set_justRolledDiceNum(int dicenum)
{
	if (dicenum > 0 && dicenum < 7)
	{
		justRolledDiceNum = dicenum;
	}
}
int Player::GetjustRolledDiceNum()const {
	return justRolledDiceNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	if (Fired && !Fire_used && SpecialAttacks_Counter < 2)
	{
		if (punishperiod < 3)
		{
			wallet -= 20;
			punishperiod++;
			pGrid->GetOutput()->PrintMessage("You are Fired Wallet: "+ to_string(wallet) +"...click to continue");
			pGrid->GetInput()->GetCellClicked();
			pGrid->GetOutput()->ClearStatusBar();
		}
		else{
		Fired = false;
		Fire_used = true;
		SpecialAttacks_Counter++;
		}
	}
	if (Poisoned && !Poison_used && SpecialAttacks_Counter < 2)
	{
		if (punishperiod < 5)
		{
			diceNumber--;
			punishperiod++;
			pGrid->GetOutput()->PrintMessage("You are Poisoned dice Number: " + to_string(diceNumber) + "...click to continue");
			pGrid->GetInput()->GetCellClicked();
			pGrid->GetOutput()->ClearStatusBar();
		}
		else {
			Poisoned = false;
			Poison_used = true;
			SpecialAttacks_Counter++;
		}
	}
	if (prevented && !prevent_used && SpecialAttacks_Counter < 2)
	{
		pGrid->GetOutput()->PrintMessage("You are Prevented from Playing ...click to continue");
		pGrid->GetInput()->GetCellClicked();
		pGrid->GetOutput()->ClearStatusBar();
		turnCount++;
		if (turnCount > 3)
		{
			turnCount = 0;
		}
		prevented = false;
		prevent_used = true;
		SpecialAttacks_Counter++;
		return;
	}

	// == Here are some guideline steps (numbered below) to implement this function ==
	if (Roll == false)
	{
		Roll = true;
		turnCount++;
		return;
	}
	else {
		if (freeze)
		{
			turnCount++;
			if (turnCount > 3)
			{
				if (SpecialAttacks_Counter < 2)
				{
					pGrid->GetOutput()->PrintMessage("Do you wish to launch a special attack instead of recharging? y/n");
					if (pGrid->GetInput()->GetSrting(pGrid->GetOutput()) == "y")
					{
						pGrid->GetOutput()->ClearStatusBar();
						SpecialAttacks(pGrid, diceNumber);
						turnCount = 0;
						return;
					}
					else
					{
						pGrid->GetOutput()->ClearStatusBar();
						wallet = wallet + (diceNumber * 10);

						turnCount = 0;
						return;
					}

				}
				else {
					wallet = wallet + (diceNumber * 10);
					turnCount = 0;
					return;
				}
			}
			pCell->GetGameObject()->Apply(pGrid, this);
			return;
		}
		// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
		turnCount++;
		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		if (turnCount > 3)
		{
			if (SpecialAttacks_Counter < 2)
			{
				pGrid->GetOutput()->PrintMessage("Do you wish to launch a special attack instead of recharging? y/n");
				if (pGrid->GetInput()->GetSrting(pGrid->GetOutput()) == "y")
				{
					pGrid->GetOutput()->ClearStatusBar();
					SpecialAttacks(pGrid, diceNumber);
					turnCount = 0;
					return;
				}
				else
				{
					pGrid->GetOutput()->ClearStatusBar();
					wallet = wallet + (diceNumber * 10);

					turnCount = 0;
					return;
				}

			}
			else {
				wallet = wallet + (diceNumber * 10);
				turnCount = 0;
				return;
			}
		}
		else {
			// 3- Set the justRolledDiceNum with the passed diceNumber
			 justRolledDiceNum=diceNumber;
			// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
			//    Using the appropriate function of CellPosition class to update "pos"
			Player* pPlayer = pGrid->GetCurrentPlayer();
			CellPosition pos((pPlayer->GetCell()->GetCellPosition()).GetCellNum());
			int posnum = pos.GetCellNum();
			posnum = posnum + diceNumber;
			pos = pos.GetCellPositionFromNum(posnum);
			// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
			//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
			pGrid->UpdatePlayerCell(pPlayer, pos);
			// 6- Apply() the game object of the reached cell (if any)
			GameObject* g = pPlayer->pCell->GetGameObject();
			if (g != NULL) {
				g->Apply(pGrid, pPlayer);
			}
			pGrid->UpdateInterface();
			
			// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
			if (pos.GetCellNum() > 99)
				pGrid->SetEndGame(true);
		}
	}
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
void Player::SpecialAttacks(Grid* pGrid, int diceNumber)
{
	pGrid->GetOutput()->PrintMessage("Choose Your Special Attack .. Ice[1]-Fire[2]-Poison[3]-Lightning[4]..");
	switch (pGrid->GetInput()->GetInteger(pGrid->GetOutput()))
	{
	case 1:
		pGrid->SpecialAttack_ICE();
		break;
	case 2:
		pGrid->SpecialAttack_FIRE();
		break;
	case 3:
		pGrid->SpecialAttack_POISON();
		break;
	case 4:
		pGrid->SpecialAttack_LIGHTNING(this);
		break;
	default:
		break;
	}
}
