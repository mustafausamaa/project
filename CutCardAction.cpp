#include "CutCardAction.h"
#pragma once
#include"Card.h"
#include"Grid.h"
#include"Cell.h"
#include"CellPosition.h"
#include"CopyCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : CopyCardAction(pApp)
{
	ptr = NULL;
}


CutCardAction::~CutCardAction()
{
}



CellPosition CutCardAction::getLast()const {
	return pos;
}

void CutCardAction::ReadActionParameters() {

	Grid* pGrid = pManager->GetGrid();
	Input* iptr = pGrid->GetInput();
	Output* optr = pGrid->GetOutput();

	pGrid->PrintErrorMessage("Click on a Card to be added to Clipboard ...");
	pos = iptr->GetCellClicked();

	ptr = dynamic_cast<Card*>(pGrid->getgameobject(pos));
	if (ptr == NULL) {
		pGrid->PrintErrorMessage("No Card inside the cell ! Click to Continue ");
		return;
	}

	pGrid->SetClipboard(ptr);
	pGrid->setClipboardFlag(1);
	pGrid->PrintErrorMessage("Card successfully added to Clipboard ! Click to Continue");


}

void CutCardAction::Execute() {

	ReadActionParameters();
	/// de tet3emel fel pastee msh henaaa	Grid* pGrid=pManager->GetGrid();
	// pGrid->RemoveObjectFromCell(pos);
}