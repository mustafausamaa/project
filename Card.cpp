#include "Card.h"


Card::Card(const CellPosition& pos) : GameObject(pos), ObjType(card) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);

}

void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::Save(ofstream& OutFile, GOType Type)
{
		if (Type == ObjType)
		{
			CellPosition temp;
			temp = GetPosition();
			
			OutFile <<cardNumber<<"\t"<< temp.GetCellNum() <<"\t" << endl; //there is still a missing implementation

		}
		else { return; }
	

}

void Card::Load(ifstream& Infile, GOType Type, CellPosition& start2, CellPosition& end2)
{
}
bool Card::IsOverlapping(GameObject* newObj)const {

	Card* pCard = dynamic_cast<Card*>(newObj);
	if (pCard == NULL) {
		return 0;
	}


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->GetPosition().VCell() == newObj->GetPosition().VCell() && this->GetPosition().HCell() == newObj->GetPosition().HCell())
			{
				return true;
			}
		}
	}

	return false;
}

Card::~Card()
{
}