#pragma once

#include"BaseAgent.h"

class UserAgent :public BaseAgent
{
public:
	//oselo��obj,my_color��color��ݒ�
	UserAgent(const std::shared_ptr<OseloClass> &obj, const int &color);

	//���[�U���΂�u��
	void Put();
};