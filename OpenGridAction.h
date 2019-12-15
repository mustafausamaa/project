#pragma once
#include"SaveGridAction.h"
#include "Action.h"
#include"Ladder.h"
#include "Snake.h"
#include "Card.h"
#include<fstream>

class OpenGridAction:public Action
{
	ifstream pOpen;
	string name;
public:
	OpenGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

