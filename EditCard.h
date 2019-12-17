#pragma once
#include"AddCardAction.h"
#include"Action.h"
#include"Grid.h"
#include"Cell.h"


class EditCard:public Action
{
	int cardnum;
	CellPosition card;
	bool HasCard;
public:
	EditCard(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

