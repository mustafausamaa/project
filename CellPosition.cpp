#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	if (v < NumVerticalCells && v >= 0)
	{
		vCell = v;
		return true;
	}
	else return false; // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	if (h < NumHorizontalCells && h >= 0)
	{
		hCell = h;
		return true;
	}
	else return false;
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	if (hCell < NumHorizontalCells && hCell >= 0 && vCell < NumVerticalCells && vCell >= 0)
			return true;
	else return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	if (cellPosition.HCell() < NumHorizontalCells && cellPosition.HCell() >= 0 && cellPosition.VCell() >= 0 && cellPosition.VCell() < NumVerticalCells)
	{
		int h = cellPosition.HCell();
		int v = cellPosition.VCell();
		v = NumVerticalCells -1-v;
		int cellnum = 0;
		cellnum = (NumHorizontalCells * v) + 1 + h;
		// Note:
		// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
		// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

		///TODO: Implement this function as described in the .h file

		return cellnum; // this line should be changed with your implementation
	}
	return -1;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	if (cellNum <= 99 && cellNum > 0)
	{
		CellPosition position;
		int v = 0, h = 0;
		for (int i = 0; i <= (NumVerticalCells - 1); i++)
		{
			if ((cellNum >= ((NumHorizontalCells * i) + 1)) && (cellNum <= (NumHorizontalCells + (NumHorizontalCells * i))))
			{
				v = i;
				h = cellNum - (NumHorizontalCells * i + 1);
				v = NumVerticalCells - 1 - v;
				break;
			}

		}
		position.SetHCell(h);
		position.SetVCell(v);
		return position;
	}
	return CellPosition(-1,-1);
	/// TODO: Implement this function as described in the .h file



	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it



}

void CellPosition::AddCellNum(int addedNum)
{
	/// TODO: Implement this function as described in the .h file
	int cellnum = 0;
	cellnum = GetCellNum();
	cellnum += addedNum;
	if (cellnum > 99)
		cellnum = 99;
	GetCellPositionFromNum(cellnum);


	// Note: this function updates the data members (vCell and hCell) of the calling object

}