#pragma once

#include<memory>
#include<DxFunc.h>
#include"CellMGR.h"
#include"RateClass.h"
using namespace std;
class BaseAgent:public RateClass
{
protected:
	shared_ptr<C lMGR> cells;

public:
	BaseAgent(const shared_ptr<CellMGR> &cells) 
		:cells(cells) {}
	virtual int Put(const Input &input) = 0;
};