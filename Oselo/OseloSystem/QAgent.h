#pragma once

#include"stdafx.h"
#include"Hash.h"
#include"../../../MachineLearning/ReinforcementLearning/QLearning/QLearning/QLClass.h"

#include"BaseAgent.h"

class QAgent :public BaseAgent
{
private:
	QLClass<BoardClass, CellCoord> ql_obj;
	bool learn_flag;

public:
	QAgent(const std::shared_ptr<OseloClass> &obj, const int &color,const bool &learn_flag=true);

	virtual void Put();

	void LoadFile(const string &file_name)
	{
		this->ql_obj.LoadFile(file_name);
	}

	void WriteFile(const string &file_name)
	{
		this->ql_obj.WriteFile(file_name);
	}
};