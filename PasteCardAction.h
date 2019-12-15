#pragma once
#include"CellPosition.h"
#include"Card.h"
#include"Grid.h"
#include"Cell.h"
#include"CutCardAction.h"
#include"CopyCardAction.h"
//// Hatwadeehoom  el.cppp Lazemm 
#include "CardOne.h"
#include "CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

class PasteCardAction :  public CutCardAction ,public Card
{
	
	CellPosition into;
	Card* getter;
public:
	PasteCardAction(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute(); 
	
	~PasteCardAction();



};

