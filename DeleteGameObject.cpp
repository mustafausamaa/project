#include "DeleteGameObject.h"
#include"Output.h"
#include"Input.h"
#include"Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager *pApp)
	:Action(pApp)
{
	GameObjectExist=false;
}

void DeleteGameObject::ReadActionParameters()
{

	Grid *pGrid=pManager->GetGrid();
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	pOut->PrintMessage("Click on The cell you want to delete");
	object=pIn->GetCellClicked();
	Cell test(object);
	GameObject *ptr=NULL;
	ptr=test.GetGameObject();
	if(ptr)
	{
		GameObjectExist=true;
	}


}
void DeleteGameObject::Execute()
{
	Grid *pGrid=pManager->GetGrid();
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	ReadActionParameters();
	if(GameObjectExist==true)
	{
		pGrid->RemoveObjectFromCell(object);
		pGrid->PrintErrorMessage("Object Successfully removed from cell");
	}
	else
		pGrid->PrintErrorMessage("No Object Exists in this cell");

}

