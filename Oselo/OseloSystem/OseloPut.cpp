#include"stdafx.h"

#include"OseloClass.h"
#include"OseloSystem.h"

using namespace std;

void OseloClass::Init()
{
	OseloSystem::Init(&this->board);
}

//盤面にcolorの石を配置
bool OseloClass::Put(const CellCoord &coord)
{
	return OseloSystem::Put(&this->board, coord, this->current_turn);
}


//盤面の中央に石を配置
void OseloSystem::Init(BoardClass *board)
{
	board->Init();
}

bool OseloSystem::Put(BoardClass *board, const CellCoord &coord, const int &color)
{
	Flip flip;

	if (CheckPut(*board, coord, color, &flip))
	{
		PutState state(coord, flip, color);
		board->PutPiecesAt(state);

		return true;
	}

	return false;
}