#include"stdafx.h"

#include"Hash.h"
#include"AgentImpl.h"
#include"QAgent.h"
#include"OseloSystem.h"
#include<StringPlus.h>

void QAgent::Put()
{
	this->base_pimpl->DispTurn();

	auto s = this->base_pimpl->oselo->GetBoard();
	
	auto a=this->q_pimpl->ql_obj.Learn(s);
	this->base_pimpl->oselo->Put(a);
}