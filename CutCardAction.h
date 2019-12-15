#pragma once
#include"Card.h"
#include"Grid.h"
#include"Cell.h"
#include"CellPosition.h"
#include"CopyCardAction.h"

class CutCardAction : public CopyCardAction
{
	bool flag;
	Card* ptr;
	CellPosition pos;
public:
	CutCardAction(ApplicationManager *pApp);
	
	CellPosition getLast()const;

	void ReadActionParameters();
	
	~CutCardAction();

	virtual void Execute();
	
};

