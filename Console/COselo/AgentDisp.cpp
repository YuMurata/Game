#include"BaseAgent.h"

#include<iostream>
#include<typeinfo>

using namespace std;

//��ԕ\��
void BaseAgent::DispTurn()const
{
	const char *turn[] =
	{
		"BLACK",
	"WHITE",
	};

	cout << typeid(*this).name() << ":" << turn[this->my_color] << endl;
}
