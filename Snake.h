#pragma once

#include "GameObject.h"

class Snake : public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	const GOType ObjType;

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	virtual void Save(ofstream& OutFile, GOType Type);	// Saves the GameObject parameters to the file
	virtual void Load(ifstream& Infile, GOType Type, CellPosition& start, CellPosition& end);
	bool IsOverlapping(GameObject* newObj)const;
	virtual ~Snake(); // Virtual destructor
};
