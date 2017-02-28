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

	std::pair<PutState,PutState> Init();

	void DrawBoard()const;
	
	bool CheckFinish()const;

	int GetCurrent()const;

	void ChangeTurn();

	bool CheckPutable()const;

	PutState Put(const CellCoord &coord);

	BoardClass GetBoard()const;

	PutState Undo();

	bool Redo();

	int GetWin()const;
};