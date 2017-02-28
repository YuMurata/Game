#pragma once

#include"stdafx.h"

#include<Coordinate.h>

#include<vector>
#include<functional>

using CellCoord = TCoordinate<int>;

class PutState
{
public:
	CellCoord put;//�u�������W
	std::vector<CellCoord> flip;//���Ԃ������W
	int color;//�F

	PutState()
		:PutState(CellCoord(), std::vector<CellCoord>(), 0) {}

	PutState(const CellCoord &put, const std::vector<CellCoord> &flip, const int &color)
		:put(put), flip(flip), color(color) {}

	bool IsPut()const
	{
		return !this->flip.empty();
	}
};