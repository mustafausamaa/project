#include "SaveGridAction.h"


SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp)
{

}


void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter file Name to save data...");
	name = pGrid->GetInput()->GetSrting(pOut);
	save.open(name + ".txt", ios::out);
	NofLadders = pGrid->numofladders();
	NofSnakes = pGrid->numofSnakes();
	NofCards = pGrid->numofCards();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	save << NofLadders << endl;
	pGrid->SaveAll(save, ladder);
	save << NofSnakes << endl;
	pGrid->SaveAll(save, snake);
	save << NofCards << endl;
	pGrid->SaveAll(save, card);
	save.close();
	pGrid->PrintErrorMessage("The Grid has been saved in text file " + name + ".txt...");

}
