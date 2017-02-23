#pragma once
#include"stdafx.h"

#include"BaseAgent.h"
#include<Randomer.h>

class RandomAgent :public BaseAgent,Randomer
{
private:
	std::uniform_int_distribution<> putter_x;
	std::uniform_int_distribution<> putter_y;

public:
	RandomAgent(const std::shared_ptr<OseloClass> &obj, const int &color);

	virtual void Put();

};