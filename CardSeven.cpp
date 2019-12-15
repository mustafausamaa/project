#include "CardSeven.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"
CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number (1 here)
}


CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{

	// No parameters

}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below)  to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
/////	pGrid->PrintErrorMessage("Player " + to_string(pGrid->get_currplayernum()) + " will roll the dice again.Click to continue ...");
/////	int temp = pGrid->get_currplayernum();
/////	pGrid->set_currplayernum(temp - 1);

}

