#include"CardTen.h"

bool CardTen::Isbought = false;
int CardTen::CardPrice = 0;
int CardTen::Fees = 0;
Player* CardTen::pOwner = NULL;
bool CardTen::IsInitialized = false;
CardTen::CardTen(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 10;

}

void CardTen::ReadCardParameters(Grid* pGrid)
{
	//TODO

	//1- Get Pointers to input and output
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	//2- Read Integers from user indicating CardPrice and Fees
	if (IsInitialized == false)
	{
		pOut->PrintMessage("New CardTen: Please Enter Card Price.....");
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

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
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
				pOut->PrintMessage("Card Successfully Bought");
				pOut->ClearStatusBar();
				pOwner = pPlayer;
			}
			else
			{
				pOut->PrintMessage("Sorry, your current wallet is less than the card price");
				pOut->ClearStatusBar();
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
				pOut->PrintMessage("Fees Successfully paid");
				pOut->ClearStatusBar();

			}

		}
		else
		{
			pOut->PrintMessage("You don't have enough coins to pay the fees");
			pOut->ClearStatusBar();
		}
	}
}