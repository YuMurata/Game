#include"AgentImpl.h"

//Žè”Ô•\Ž¦
void BaseAgent::Impl::DispTurn()const
{
	const char *turn[] =
	{
		"BLACK",
		"WHITE",
	};

	cout << typeid(*this).name() << ":" << turn[this->my_color] << endl;
}

