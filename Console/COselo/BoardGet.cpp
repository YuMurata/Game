#include"BoardImpl.h"

using namespace std;

//盤面の大きさを取得
BoardClass::CellNum BoardClass::GetBoardSize()const
{
	return this->pimpl->board_size;
}

//座標coordの状態を取得
int BoardClass::GetCellState(const CellCoord &coord)const
{
	return this->pimpl->board[coord.y][coord.x];
}

//色colorの石数を取得
int BoardClass::GetCellNum(const int &color)const
{
	return this->pimpl->cell_num[color];
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

BoardClass::Board BoardClass::GetBoard()const
{
	return this->pimpl->board;
}