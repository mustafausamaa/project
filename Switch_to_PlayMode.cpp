#include "Switch_to_PlayMode.h"
Switch_to_PlayMode::Switch_to_PlayMode(ApplicationManager* pApp) : Action(pApp)
{
}

void Switch_to_PlayMode::ReadActionParameters()
{


}

void Switch_to_PlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	pOut->CreatePlayModeToolBar();
	pManager->ExecuteAction(NEW_GAME);
}

Switch_to_PlayMode::~Switch_to_PlayMode()
{
}