#pragma once

#include"../../MachineLearning/ReinforcementLearning/QLearning/QLearning/QLClass.h"

#include"BaseAgent.h"
#include"OseloSystem.h"
#include<StringPlus.h>

#include"Hash.h"

class QAgent :public BaseAgent
{
private:
	class Impl;
	unique_ptr<Impl> q_pimpl;
	
public:
	void Put();

	QAgent(const shared_ptr<OseloClass> &obj, const int &color);
	virtual ~QAgent();

	void LoadFile(const string &file_name);

	void WriteFile(const string &file_name);
};