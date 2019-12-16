#include "OpenGridAction.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include"CardEleven.h"
#include "CardTwelve.h"
#include "CardFourteen.h"
#include "CardThirteen.h"

OpenGridAction::OpenGridAction(ApplicationManager* pApp) : Action(pApp)
{

}

void OpenGridAction::ReadActionParameters()
{

	Grid* pGrid = Action::pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter file Name to save data...");
	name = pGrid->GetInput()->GetSrting(pOut);
	pOpen.open(name+".txt");
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = Action::pManager->GetGrid();
	if (pOpen.fail())
	{
		pGrid->PrintErrorMessage("Error openeing txt file...");

	}
	else {
		pGrid->DeleteAll();
		pGrid->UpdateInterface();
		int NofLadders;
		pOpen >> NofLadders;
		for (int i = 0; i < NofLadders; i++)
		{
			Ladder* pLadder;
			CellPosition start1;
			CellPosition end1;
			pLadder = new Ladder(start1, end1);
			pLadder->Load(pOpen, ladder, start1, end1);
			delete pLadder;
			pLadder = new Ladder(start1, end1);
			pGrid->AddObjectToCell(pLadder);
			pGrid->GetOutput()->DrawLadder(start1, end1);
		}
		int NofSnakes;
		pOpen >> NofSnakes;
		for (int i = 0; i < NofSnakes; i++)
		{
			Snake* pSnake;
			CellPosition start1;
			CellPosition end1;
			pSnake = new Snake(start1, end1);
			pSnake->Load(pOpen, snake, start1, end1);
			delete pSnake;
			pSnake = new Snake(start1, end1);
			pGrid->AddObjectToCell(pSnake);
			pGrid->GetOutput()->DrawSnake(start1, end1);
		}
		int NofCards;
		pOpen >> NofCards;
		for (int i = 0; i < NofCards; i++)
		{
			int cardnum, cellnum;
			pOpen >> cardnum >> cellnum;
			Card* pCard;
			CellPosition cardPosition(cellnum);
			CellPosition null;
			switch (cardnum)
			{
			case 1:
				pCard = new CardOne(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 2:
				pCard = new CardTwo(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 3:
				pCard = new CardThree(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 4:
				pCard = new CardFour(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 5:
				pCard = new CardFive(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 6:
				pCard = new CardSix(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
				break;
			case 7:
				pCard = new CardSeven(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 8:
				pCard = new CardEight(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 9:
				pCard = new CardNine(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 10:
				pCard = new CardTen(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 11:
				pCard = new CardEleven(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 12:
				pCard = new CardTwelve(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 13:
				pCard = new CardThirteen(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			case 14:
				pCard = new CardFourteen(cardPosition);
				pCard->Load(pOpen, card, cardPosition, null);
				break;
			}

			pCard->SetCardNumber(cardnum);
			pGrid->AddObjectToCell(pCard);

			pGrid->GetOutput()->DrawCell(cardPosition, pCard->GetCardNumber());
		}

		pGrid->PrintErrorMessage("The Grid has been Loaded from text file " + name + ".txt...");
	}
}
