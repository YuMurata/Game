#include"BoardImpl.h"

using namespace std;

//�Ֆʂ̑傫�����擾
BoardClass::CellNum BoardClass::GetBoardSize()const
{
	return this->pimpl->board_size;
}

//���Wcoord�̏�Ԃ��擾
int BoardClass::GetCellState(const CellCoord &coord)const
{
	return this->pimpl->board[coord.y][coord.x];
}

//�Fcolor�̐ΐ����擾
int BoardClass::GetCellNum(const int &color)const
{
	return this->pimpl->cell_num[color];
}

//�����ق��̐F���擾
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