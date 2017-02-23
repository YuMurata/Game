#include"stdafx.h"

#include"BoardClass.h"

#include<iterator>
#include<algorithm>

using namespace std;

//cell_num‚Écell_num‚ðÝ’è
BoardClass::BoardClass(const CellNum &board_size)
	:board_size(board_size), cell_num(Cell_NUM) {}

//”Õ–Ê‚Ì‰Šú‰»
void BoardClass::Init()
{
	this->board =
		vector<vector<int>>(this->board_size.y, vector<int>(this->board_size.x, Cell_Empty));
	this->undo = stack<PutState>();
	this->redo = stack<PutState>();

	const auto mid = this->board_size / (CellNum)2;

	const int black = BoardClass::Cell_BLACK;
	const int white = BoardClass::Cell_WHITE;

	const CellCoord left_top(mid.x - 1, mid.y - 1);
	const CellCoord left_down(mid.x - 1, mid.y);

	const CellCoord right_top(mid.x, mid.y - 1);
	const CellCoord right_down(mid.x, mid.y);

	const int init_num = 4;

	int color[init_num] =
	{
		black,white,
		white,black
	};

	CellCoord coord[init_num] =
	{
		left_top,right_top,
		left_down,right_down
	};

	for (int i = 0; i < init_num; ++i)
	{
		this->PutPieceAt(coord[i], color[i]);
	}
}


std::ostream& operator<<(std::ostream& stream, const BoardClass& value)
{
	auto func = [&](const vector<int> &input)
	{
		copy(begin(input), end(input), ostream_iterator<int>(stream, ","));
	};

	for_each(begin(value.board), end(value.board), func);

	return stream;
};