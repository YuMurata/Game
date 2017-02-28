#include"stdafx.h"

#include"OseloClass.h"

#include"OseloSystem.h"

using namespace std;

//�Ֆʂ̕`��
void OseloClass::DrawBoard()const
{
	OseloSystem::DrawBoard(this->board);
}

//�Ֆʂ̕`��
void OseloSystem::DrawBoard(const BoardClass &board)
{
	const char *cell[] =
	{
		"��","��","��",
	};

	const string line = "------------------";

	cout << endl << line << line << endl << endl;

	auto board_size = board.GetBoardSize();

	cout << "  ";
	for (int x = 0; x < board_size.x; ++x)
	{
		cout << x << "  ";
	}
	cout << endl;

	CellCoord coord;
	for (coord.y = 0; coord.y < board_size.y; ++coord.y)
	{
		cout << char('a' + coord.y) << " ";
		for (coord.x = 0; coord.x < board_size.x; ++coord.x)
		{
			auto color = board.GetCellState(coord) + 1;
			cout << cell[color] << " ";
		}
		cout << char('a' + coord.y) << endl;
	}


	cout << "  ";
	for (int x = 0; x < board_size.x; ++x)
	{
		cout << x << "  ";
	}

	cout << endl << line << line << endl << endl;

}

//�΂̐���\��
void OseloSystem::DispCells(const int &black_count, const int &white_count)
{
	cout << "[BLACK]:" << black_count << endl;
	cout << "[WHITE]:" << white_count << endl;
}

//�΂�z�u�ł��Ȃ��ꍇ�ɌĂяo��
void OseloSystem::Pass(const int &color)
{
	const string turn_color[] =
	{
		"BLACK",
		"WHITE",
	};

	cout << "[" << turn_color[color - 1] << "] cant put !" << endl;
}