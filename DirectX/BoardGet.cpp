#include"stdafx.h"

#include"BoardClass.h"

#include<algorithm>

using namespace std;

//盤面の大きさを取得
CellNum BoardClass::GetBoardSize()const
{
	return this->board_size;
}

//座標coordの状態を取得
int BoardClass::GetCellState(const CellCoord &coord)const
{
	return this->board[coord.y][coord.x];
}

//色colorの石数を取得
int BoardClass::GetCellNum(const int &color)const
{
	return this->cell_num[color];
}

//多いほうの色を取得
int BoardClass::GetOften()const
{
	auto black = this->GetCellNum(Cell_BLACK);
	auto white = this->GetCellNum(Cell_WHITE);

	auto ret = Cell_Empty;

	if (black != white)
	{
		ret = black > white ? Cell_BLACK : Cell_WHITE;
	}

	return ret;
}

Board BoardClass::GetBoard()const
{
	return this->board;
}