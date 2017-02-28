#include"stdafx.h"

#include"Hash.h"

#include"QAgent.h"
#include"OseloSystem.h"
#include<StringPlus.h>

void QAgent::Put()
{
	this->DispTurn();

	auto s = this->oselo->GetBoard();
	
	auto a=this->pimpl->ql_obj.Learn(s);
	this->oselo->Put(a);
}