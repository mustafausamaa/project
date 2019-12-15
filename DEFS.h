#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,		// Add Snake Action	
	ADD_CARD,		// Add Card Action	
	Copy,
	Cut,
	Paste,
	Edit,
	Delete,
	Open,
	Save,
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode
	
	///TODO: Add more action types of Design Mode
	

	//  [2] Actions of Play Mode

	ROLL_DICE,		// Roll Dice Action
	INPUT_DICE_VALUE,
	TO_DESIGN_MODE,	// Go to Design Mode
	NEW_GAME,
	EXIT_2,
	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif