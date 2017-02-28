#pragma once

#include"BaseAgent.h"

#include"QAgent.h"

#include"OseloClass.h"

#include"../../MachineLearning/ReinforcementLearning/QLearning/QLearning/QLClass.h"

#include<memory>

class BaseAgent::Impl
{
public:
	std::shared_ptr<OseloClass> oselo;
	int my_color;

	void DispTurn()const;
};

class QAgent::Impl
{
public:
	QLClass<BoardClass, CellCoord> ql_obj;
};