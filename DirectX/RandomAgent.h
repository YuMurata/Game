#pragma once

#include"BaseAgent.h"
#include<Randomer.h>
#include<OseloSystem.h>
class RandomAgent :public BaseAgent, public Randomer
{
public:
	RandomAgent(const sha
 d_ptr<CellMGR> &cells)
		:BaseAgent(cells) {}

	int Put(const Input &input)
	{
		auto obj = this->cells->GetOselo();

		auto board = obj.GetBoard();
		auto color = obj.GetCurrent();

		auto putable=OseloSystem::GetPutable(board,color);
		
		shuffle(begin(putable), end(putable), this->mt);
		auto win=this->cells->PutReal(putable.front());
		this->cells->UpDate();

		return win;
	}
};