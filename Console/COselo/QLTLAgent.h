#pragma once
#include"BaseAgent.h"
#include"OseloSystem.h"
#include<StringPlus.h>

class QLTLAgent :public BaseAgent 
{
private:
	class Impl;
	unique_ptr<Impl> qltl_pimpl;

public:
	QLTLAgent(const shared_ptr<OseloClass> &obj, const int &color, const int &cell_num, const bool &learn_flag = true);

	virtual ~QLTLAgent();

	virtual void Put();

	void Review(const CellCoord &coord);

	void LoadFile(const string &file_name);

	void WriteFile(const string &file_name);
};
