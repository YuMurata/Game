#include"stdafx.h"

#include"OseloClass.h"
#include"OseloSystem.h"

OseloClass::OseloClass(const CellNum &cell_num, const int &current_turn)
:board(cell_num), current_turn(current_turn), init_turn(current_turn) {}

//turn_color‚Ì”½“]
void OseloClass::ChangeTurn()
{
	OseloSystem::ChangeTurn(&this->current_turn);
}

//turn_color‚Ì”½“]
void OseloSystem::ChangeTurn(int *turn_color)
{
	*turn_color = ((*turn_color)+1) % 2;
}