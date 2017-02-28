#include"BaseAgent.h"
#include"UserAgent.h"
#include"RandomAgent.h"
#include"QAgent.h"
#include"BoardClass.h"
#include"OseloSystem.h"

#include<StringPlus.h>

int BaseAgent::win = BoardClass::Cell_Empty;

using namespace std;

//�R���X�g���N�^

//oselo��obj,my_color��color��ݒ�
BaseAgent::BaseAgent(const shared_ptr<OseloClass> &obj, const int &color)
	:oselo(obj), my_color(color) {}

//oselo��obj,my_color��color��ݒ�
UserAgent::UserAgent(const shared_ptr<OseloClass> &obj, const int &color)
	: BaseAgent(obj, color) {}

//oselo��obj,my_color��color��ݒ�
//putter��BoardSize�ŏ�����
RandomAgent::RandomAgent(const shared_ptr<OseloClass> &obj, const int &color)
	: BaseAgent(obj, color) {}