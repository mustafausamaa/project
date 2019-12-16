#pragma once
#include "Action.h"
class DeleteGameObject :public Action
{
	bool GameObjectExist;
	CellPosition object;

public:
	DeleteGameObject(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

