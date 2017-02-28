#include"OseloSystem.h"
#include"OseloClass.h"

PutState OseloClass::Undo()
{
	auto state=OseloSystem::Undo(&this->board);
	this->ChangeTurn();
	if (!this->CheckPutable())
	{
		this->ChangeTurn();
	}

	return state;
}

bool OseloClass::Redo()
{
	return OseloSystem::Redo(&this->board);
}

PutState OseloSystem::Undo(BoardClass *board)
{
	return board->Undo();
}

bool OseloSystem::Redo(BoardClass *board)
{
	return board->Redo();
}