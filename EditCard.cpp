#include "EditCard.h"
#include"AddCardAction.h"
#include "Input.h"
#include "Output.h"
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
#include "CardEleven.h"
#include "CardTwelve.h"
#include "CardThirteen.h"
#include "CardFourteen.h"


EditCard::EditCard(ApplicationManager* pApp)
	:Action(pApp)
{
	HasCard = false;
}
void EditCard::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on The Card You Want To Edit...");
	card = pIn->GetCellClicked();
	
	if (!card.IsValidCell())
		return;

	if (pGrid->getgameobject(card))
	{
		HasCard = true;
	}
	else
		pOut->PrintMessage("No Card Exists Here");
	pOut->ClearStatusBar();
}
void EditCard::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	if (HasCard == true)
	{
		pOut->PrintMessage("Enter Edited Card Number");
		int cardnum = pIn->GetInteger(pOut);
		while (cardnum < 0 || cardnum>15)
		{
			pGrid->PrintErrorMessage("Invalid Value! Please Enter Card Number From 1 to 14");
			cardnum = pIn->GetInteger(pOut);
		}
		Card* pCard = NULL;
		switch (cardnum)
		{
		case 1:
			pCard = new CardOne(card);
			break;
		case 2:
			pCard = new CardTwo(card);
			break;
		case 3:
			pCard = new CardThree(card);
			break;
		case 4:
			pCard = new CardFour(card);
			break;
		case 5:
			pCard = new CardFive(card);
			break;
		case 6:
			pCard = new CardSix(card);
			break;
		case 7:
			pCard = new CardSeven(card);
			break;
		case 8:
			pCard = new CardEight(card);
			break;
		case 9:
			pCard = new CardNine(card);
			break;
		case 10:
			pCard = new CardTen(card);
			break;
		case 11:
			pCard = new CardEleven(card);
			break;
		case 12:
			pCard = new CardTwelve(card);
			break;
		case 13:
			pCard = new CardThirteen(card);
			break;
		case 14:
			pCard = new CardFourteen(card);
			break;

		}

		// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
		if (pCard)
		{
			// A- We get a pointer to the Grid from the ApplicationManager


			Grid* pGrid = pManager->GetGrid();

			// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
			pCard->ReadCardParameters(pGrid);

		}
	}

}