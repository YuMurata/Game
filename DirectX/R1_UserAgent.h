#pragma once

#include"BaseAgent.h"

class UserAgent :public BaseAgent
{
public:
	//oseloにobj,my_colorにcolorを設定
	UserAgent(const std::shared_ptr<OseloClass> &obj, const  t &color);

	//ユーザが石を置く
	virtual void Put();
};