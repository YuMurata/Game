#pragma once
#include"stdafx.h"

#include"OseloClass.h"
#include<memory>

class BaseAgent
{
protected:
	std::shared_ptr<OseloClass> oselo;
	int my_color;

	void DispTurn();

public:
	//oselo‚Éobj,my_color‚Écolor‚ğİ’è
	BaseAgent(const std::shared_ptr<OseloClass> &obj, const int &color);

	virtual void Put() = 0;

	int GetColor()const
	{
		return this->my_color;
	}
};