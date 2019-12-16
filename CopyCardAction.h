#pragma once
#include"Card.h"
#include"Grid.h"
#include"Cell.h"
#include"CellPosition.h"
#include"Action.h"
class CopyCardAction : public Action
{
	Card* ptr;
public:

	CopyCardAction(ApplicationManager* pApp);

	void ReadActionParameters();

	virtual ~CopyCardAction();

	virtual void Execute();
};

