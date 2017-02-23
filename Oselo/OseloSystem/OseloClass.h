#pragma once

#include"stdafx.h"

#include"BoardClass.h"
#include"PutState.h"
#include<utility>

class OseloClass
{
private:
	BoardClass board;
	int current_turn;
	const int init_turn;

public:
	OseloClass(const CellNum &cell_num, const int &current_color);

	void Init();

	void DrawBoard()const;
	
	bool CheckFinish()const;

	int GetCurrent()const;

	void ChangeTurn();

	bool CheckPutable()const;

	bool Put(const CellCoord &coord);

	BoardClass GetBoard()const;

	bool Undo()
	{
		return this->board.Undo();
	}

	bool Redo()
	{
		return this->board.Redo();
	}
};