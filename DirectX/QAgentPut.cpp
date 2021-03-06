#include"stdafx.h"

#include"Hash.h"

#include"QAgent.h"
#include"OseloSystem.h"
#include<StringPlus.h>

void QAgent::Put()
{
	this->DispTurn();

	auto s = this-> elo->GetBoard();
	
	auto a=this->ql_obj.Learn(s);
	if (!this->learn_flag)
	{
		a = this->ql_obj.BestAction(s);
	}
	this->oselo->Put(a);
}