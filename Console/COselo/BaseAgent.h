#pragma once

#include"OseloClass.h"
#include<memory>

class BaseAgent
{
protected:
	class Impl;
	std::unique_ptr<Impl> base_pimpl;

public:
	static int win;

	//oselo��obj,my_color��color��ݒ�
	BaseAgent(const std::shared_ptr<OseloClass> &obj, const int &color);
	virtual ~BaseAgent();
	virtual void Put() = 0;

	virtual void Review(const CellCoord &a)
	{

	}

	int GetColor()const;
};