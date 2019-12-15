#include "Switch_to_DesignMode.h"
Switch_to_DesignMode::Switch_to_DesignMode(ApplicationManager* pApp) : Action(pApp)
{
}

void Switch_to_DesignMode::ReadActionParameters()
{


}

void Switch_to_DesignMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreateDesignModeToolBar();
	pManager->ExecuteAction(NEW_GAME);
}

Switch_to_DesignMode::~Switch_to_DesignMode()
{
}