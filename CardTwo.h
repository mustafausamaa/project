#pragma once
#include "Card.h"

// [ CardTwo ] Summary:
// Its Apply() Function: Increments the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to Increase --> put it as a "data member" and read it in ReadCardParameters()

class CardTwo :public Card
{

	// CardTwo Parameters:
	int walletAmount; // the wallet value to increase from the player


public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardTwo which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  // by Incrementing the player's wallet by the walletAmount data member

	virtual ~CardTwo(); // A Virtual Destructor
	void Save(ofstream& OutFile, GOType Type);
	void Load(ifstream& Infile, GOType Type, CellPosition& start2, CellPosition& end2);
};

