#include "PasteCardAction.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) :CutCardAction(pApp), Card(into)
{
}

void PasteCardAction::ReadActionParameters()
{
	{

		Grid* pGrid = pManager->GetGrid();
		Input* iptr = pGrid->GetInput();
		Output* optr = pGrid->GetOutput();

		pGrid->PrintErrorMessage("Click on a cell to paste the Clipboard ! Click to Continue ...");
		CellPosition x = iptr->GetCellClicked();
		if (x.IsValidCell() == 0) {
			pGrid->PrintErrorMessage("Invalid Cell ! Click to Continue ...");
			return;
		}
		else {
			into = x;
		}
	}
}

void PasteCardAction::Execute()
{


	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Card* tst = pGrid->GetClipboard();

	bool z = 0;
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card* pCard = NULL; // will point to the card object type
	switch (tst->GetCardNumber())
	{
	case 1:
		pCard = new CardOne(into);
		break;
	case 2:
		pCard = new CardTwo(into);
		break;
	case 3:
		pCard = new CardThree(into);
		break;
	case 4:
		pCard = new CardFour(into);
		break;
	case 5:
		pCard = new CardFive(into);
		break;
	case 6:
		pCard = new CardSix(into);
		break;
	case 7:
		pCard = new CardSeven(into);
		break;
	case 8:
		pCard = new CardEight(into);
		break;

	case 9:
		pCard = new CardNine(into);
		break;
	case 10:
		pCard = new CardTen(into);
		break;
	case 11:
		pCard = new CardEleven(into);
		break;
	case 12:
		pCard = new CardTwelve(into);
		break;
	case 13:
		pCard = new CardThirteen(into);
		break;
	case 14:
		pCard = new CardFourteen(into);
		break;
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (added == false)
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}

	if (pGrid->getClipboardFlag()) {
		pGrid->RemoveObjectFromCell(pGrid->GetClipboard()->GetPosition());
		pGrid->PrintErrorMessage("Clipboard Deleted Successfully ! Click to continue ...");
	}


}

PasteCardAction::~PasteCardAction()
{
}
