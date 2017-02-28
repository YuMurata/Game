#include"BoardClass.h"
#include<iterator>
#include<algorithm>

using namespace std;

//cell_num‚Écell_num‚ğİ’è
BoardClass::BoardClass(const CellNum &board_size)
	:board_size(board_size),cell_num(BoardClass::Cell_NUM){}

//”Õ–Ê‚Ì‰Šú‰»
std::pair<PutState, PutState> BoardClass::Init()
{
	this->board = vector<vector<int>>(this->board_size.y, vector<int>(this->board_size.x, Cell_Empty));
	auto mid = this->board_size / (CellCoord)2;

	auto left_top = CellCoord(mid.x - 1, mid.y - 1);
	auto right_top = CellCoord(mid.x, mid.y - 1);
	auto left_down = CellCoord(mid.x - 1, mid.y);
	auto right_down = CellCoord(mid.x, mid.y);

	auto black = BoardClass::Cell_BLACK;
	auto white = BoardClass::Cell_WHITE;

	pair<PutState, PutState> ret;

	ret.first.color = black;
	ret.first.flip = { left_top,right_down };

	ret.second.color = white;
	ret.second.flip = { right_top,left_down };

	PutState init[] = { ret.first,ret.second };

	for (auto &i : init)
	{
		for (auto &j : i.flip)
		{
			this->PutPieceAt(j, i.color);
		}
	}

	return ret;
}

ostream& operator<<(ostream &stream, const BoardClass &board)
{
	ostream_iterator<int> out(stream, ",");

	auto board_mat=board.GetBoard();

	auto func = [&out](const vector<int> &line)
	{
		copy(begin(line), end(line), out);
	};

	for_each(begin(board_mat), end(board_mat), func);

	return stream;
}