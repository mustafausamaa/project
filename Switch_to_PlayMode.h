#pragma once
#include "Action.h"
#include "Grid.h"
class Switch_to_PlayMode :public Action
{
public:
	Switch_to_PlayMode(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~Switch_to_PlayMode();
};

