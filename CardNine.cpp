#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (9 here)
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New CardNine: Enter Cell to move to...");
	celltomoveto = pIn->GetCellClicked();

	

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}
void CardNine::Save(ofstream& OutFile, GOType Type)
{
	if (Type == card)
	{
		CellPosition temp;
		temp = GetPosition();

		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << celltomoveto.GetCellNum() << endl;

	}
	else { return; }


}
void CardNine::Load(ifstream& Infile, GOType Type, CellPosition& start2, CellPosition& end2)
{
	if (Type == card)
	{

		int celltomove;
		Infile >> celltomove;
		CellPosition temp(celltomove);
		celltomoveto.SetHCell(temp.HCell());
		celltomoveto.SetVCell(temp.VCell());
	}
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	pGrid->UpdatePlayerCell(pPlayer, celltomoveto);

}