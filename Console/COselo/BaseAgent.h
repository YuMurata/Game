#pragma once
#include"stdafx.h"

//#include"OseloClass.h"
#include<memory>
class OseloClass;
class BaseAgent
{
protected:
	class Impl;
	std::unique_ptr<Impl> pimpl;
	std::shared_ptr<OseloClass> oselo;
	int my_color;

	void DispTurn()const;

public:
	static int win;

	//oselo‚Éobj,my_color‚Écolor‚ğİ’è
	BaseAgent(const std::shared_ptr<OseloClass> &obj, const int &color);

	virtual void Put() = 0;

	virtual void Review(const CellCoord &a)
	{

	}

	int GetColor()const
	{
		return this->my_color;
	}
};