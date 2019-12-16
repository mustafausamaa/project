#include "CardFourteen.h"
bool CardFourteen::Isbought = false;
int CardFourteen::CardPrice = 0;
int CardFourteen::Fees = 0;
Player* CardFourteen::pOwner = NULL;
bool CardFourteen::IsInitialized = false;

CardFourteen::CardFourteen(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 14;
	Isbought = false;
}
void CardFourteen::Save(ofstream& OutFile, GOType Type)
{
	if (Type == card)
	{
		CellPosition temp;
		temp = GetPosition();

		OutFile << cardNumber << "\t" << temp.GetCellNum() << "\t" << CardPrice << "\t" << Fees << endl; //there is still a missing implementation

	}
	else { return; }
}
void CardFourteen::Load(ifstream& Infile, GOType Type, CellPosition& start2, CellPosition& end2)
{
	if (Type == card)
	{

		int cardprice, fees;
		Infile >> cardprice >> fees;
		CardPrice = cardprice;
		Fees = fees;
	}
}

void CardFourteen::ReadCardParameters(Grid* pGrid)
{
	//TODO

	//1- Get Pointers to input and output
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	//2- Read Integers from user indicating CardPrice and Fees
	if (IsInitialized == false)
	{
		pOut->PrintMessage("New Card 14: Please Enter Card Price.....");
		CardPrice = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter Card Fees:");
		Fees = pIn->GetInteger(pOut);
		IsInitialized = true;
	}
	while (CardPrice < 0 || Fees < 0)
	{
		pGrid->PrintErrorMessage("Invalid value! please enter a positive value");
		pOut->PrintMessage("New CardTen: Please Enter Card Price.....");
		CardPrice = pIn->GetInteger(pOut);
		pOut->PrintMessage("Enter Card Fees:");
		Fees = pIn->GetInteger(pOut);

	}


	//3- clear status bar
	pOut->ClearStatusBar();


}

void CardFourteen::Apply(Grid* pGrid, Player* pPlayer)
{

	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	if (Isbought == false)
	{
		pOut->PrintMessage("Buy Card? y/n");
		string x = pIn->GetSrting(pOut);
		if (x == "y" || x == "Y")
		{
			if (pPlayer->GetWallet() >= CardPrice)
			{

				Isbought = true;
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				pGrid->PrintErrorMessage("Card Successfully Bought");

				pOwner = pPlayer;
			}
			else
			{

				pGrid->PrintErrorMessage("Sorry, your current wallet is less than the card price");

			}
		}
	}
	if (Isbought == true)
	{
		if (pPlayer != pOwner)
		{
			if (pPlayer->GetWallet() >= Fees)
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - Fees);
				pOwner->SetWallet(pOwner->GetWallet() + Fees);
				pGrid->PrintErrorMessage("Fees Successfully paid");
				pPlayer->setfreeze(false);
				pOut->ClearStatusBar();

			}
			else
			{
				pGrid->PrintErrorMessage("You don't have enough coins to pay the fees");
				pPlayer->setfreeze(true);
			}

		}

	}
}
