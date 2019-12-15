#pragma once
#include"Card.h"


class CardTwelve : public Card
{
	int CardPrice;
	int Fees;
	bool Isbought;
	Player *pOwner;
public:
	CardTwelve(const CellPosition & pos);
	void Save(ofstream& OutFile, GOType Type);
	void Load(ifstream& Infile, GOType Type, CellPosition& start2, CellPosition& end2);
	void ReadCardParameters(Grid *pGrid);// 
	void Apply(Grid *pGrid, Player *pPlayer); /*Has two parts
												1-Checks if the card is bought or not
												1.1-If it is not we should give the player the option to buy it or not
												1.1.1- if the user choose yes we check his wallet and compare it to the cardprice
														and make isbought true and make the player pointer equals to owner
														(if the player passes by a snake and  passes by the card he doesn't pay)
												1.2 - if the user chooses no nothing changes
												2- if the card is bought:
												2.1- checks if the passed player is the owner or not
												2.1.1 - if he is the owner nothing changes
												2.1.2 - if Not:
														the passed player should pay the fees
														if he doesn't have enough money the player shouldn't move.*/
};
