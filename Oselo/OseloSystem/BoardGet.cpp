#include"stdafx.h"

#include"BoardClass.h"

#include<algorithm>

using namespace std;

//�Ֆʂ̑傫�����擾
CellNum BoardClass::GetBoardSize()const
{
	return this->board_size;
}

//���Wcoord�̏�Ԃ��擾
int BoardClass::GetCellState(const CellCoord &coord)const
{
	return this->board[coord.y][coord.x];
}

//�Fcolor�̐ΐ����擾
int BoardClass::GetCellNum(const int &color)const
{
	return this->cell_num[color];
}

//�����ق��̐F���擾
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