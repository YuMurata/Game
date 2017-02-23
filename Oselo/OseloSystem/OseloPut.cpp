#include"stdafx.h"

#include"OseloClass.h"
#include"OseloSystem.h"

using namespace std;

void OseloClass::Init()
{
	OseloSystem::Init(&this->board);
}

//ีสษcolorฬฮ๐zu
bool OseloClass::Put(const CellCoord &coord)
{
	return OseloSystem::Put(&this->board, coord, this->current_turn);
}


//ีสฬษฮ๐zu
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