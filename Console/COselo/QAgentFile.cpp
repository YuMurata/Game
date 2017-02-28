#include"QAgent.h"
#include"QImpl.h"

void QAgent::LoadFile(const string &file_name)
{
	this->pimpl->ql_obj.LoadFile(file_name);
}

void QAgent::WriteFile(const string &file_name)
{
	this->pimpl->ql_obj.WriteFile(file_name);
}