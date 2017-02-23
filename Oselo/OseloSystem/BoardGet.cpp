#include"stdafx.h"

#include"BoardClass.h"

#include<algorithm>

using namespace std;

//”Õ–Ê‚Ì‘å‚«‚³‚ðŽæ“¾
CellNum BoardClass::GetBoardSize()const
{
	return this->board_size;
}

//À•Wcoord‚Ìó‘Ô‚ðŽæ“¾
int BoardClass::GetCellState(const CellCoord &coord)const
{
	return this->board[coord.y][coord.x];
}

//Fcolor‚ÌÎ”‚ðŽæ“¾
int BoardClass::GetCellNum(const int &color)const
{
	return this->cell_num[color];
}

//‘½‚¢‚Ù‚¤‚ÌF‚ðŽæ“¾
int BoardClass::GetOften()const
{
	auto black = this->GetCellNum(Cell_BLACK);
	auto white = this->GetCellNum(Cell_WHITE);

	if (black == white)
	{
		return BoardClass::Cell_Empty;
	}
	else
	{
		return max(black, white);
	}
}

Board BoardClass::GetBoard()const
{
	return this->board;
}