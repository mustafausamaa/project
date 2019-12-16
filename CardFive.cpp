#include "CardFive.h"
#include"Ladder.h"
#include"Snake.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{

	// No Parameters Needed here .....
	pGrid->GetOutput()->ClearStatusBar();

}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);


	int justrolled = pPlayer->GetjustRolledDiceNum();

	pPlayer->Move(pGrid, justrolled);

	// Checking if cell has ladder or snake  or not <<
	// First check game object  >>>> Dynamic Casting ufing has ladder // has snake ...

	if (pPlayer->GetCell()->GetGameObject()) {
		if (Ladder* pLadder = pPlayer->GetCell()->HasLadder()) {
			pLadder->Apply(pGrid, pPlayer);
		}
		if (Snake* pSnake = pPlayer->GetCell()->HasSnake()) {
			pSnake->Apply(pGrid, pPlayer);
		}
	}

}
