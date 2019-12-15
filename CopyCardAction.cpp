#pragma once
#include"Card.h"
#include"Grid.h"
#include"Cell.h"
#include"CellPosition.h"

#include"CopyCardAction.h"

CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	ptr = NULL;
}

CopyCardAction::~CopyCardAction()
{

}


void CopyCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Input* iptr = pGrid->GetInput();
	Output* optr = pGrid->GetOutput();

	pGrid->PrintErrorMessage("Click on a Card to be added to Clipboard !  Click to Continue");
	CellPosition tst = iptr->GetCellClicked();

	ptr = dynamic_cast<Card*>(pGrid->getgameobject(tst));
	if (ptr == NULL) {
		pGrid->PrintErrorMessage("No Card inside the cell ! Click to Continue");
		return;
	}

	pGrid->SetClipboard(ptr);
	pGrid->setClipboardFlag(0);
	pGrid->PrintErrorMessage("Card successfully added to Clipboard ! Click to Continue");


}


void CopyCardAction::Execute() {

	ReadActionParameters();

}
