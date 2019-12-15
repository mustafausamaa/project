#include "CardEight.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"
CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (1 here)
}


CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	// No parameters
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below)  to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pGrid->GetOutput()->PrintMessage("Player " + to_string(pGrid->get_currplayernum()) + " you are denied from playing this turn. Click to continue");
	pPlayer->set_roll(false);


}

