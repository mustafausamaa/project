#include "Snake.h"
#include "Player.h"
#include"Grid.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos), ObjType(snake)
{
	if (startCellPos.HCell() != endCellPos.HCell() || startCellPos.GetCellNum() < endCellPos.GetCellNum())
		return;

	this->endCellPos = endCellPos;

	///TODO: Do the needed validation

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	CellPosition pos = this->GetEndPosition();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	//Output* pOut = new Output;
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	pGrid->UpdatePlayerCell(pPlayer, pos);
	//    Review the "pGrid" functions and decide which function can be used for that

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

void Snake::Save(ofstream& OutFile, GOType Type)
{
	if (Type == ObjType)
	{
		CellPosition temp;
		temp = GetPosition();
		OutFile << temp.GetCellNum() << "\t" << endCellPos.GetCellNum() << endl;

	}
	else { return; }
}

void Snake::Load(ifstream& Infile, GOType Type, CellPosition& start2, CellPosition& end2)
{
	if (Type == snake)
	{

		int start, end;
		Infile >> start >> end;
		CellPosition temp(start);
		CellPosition temp1(end);
		end2.SetHCell(temp1.HCell());
		end2.SetVCell(temp1.VCell());
		start2.SetHCell(temp.HCell());
		start2.SetVCell(temp.VCell());

	}
}
bool Snake::IsOverlapping(GameObject* newObj)const
{

	Snake* pSnake = dynamic_cast<Snake*>(newObj);
	if (!pSnake)
		return 0;

	if (this->GetPosition().HCell() != pSnake->GetPosition().HCell())
		return 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = pSnake->GetEndPosition().VCell(); j > pSnake->GetPosition().VCell(); j--)
		{
			for (int k = this->GetEndPosition().VCell(); k > GetPosition().VCell(); k--)
			{
				if (k == j)
					return 1;
			}  // the cell already contains a game object
		}
	}
	return 0;
}

Snake::~Snake()
{
}