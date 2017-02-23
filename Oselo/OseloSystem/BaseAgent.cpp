#include"stdafx.h"

#include"BaseAgent.h"
#include"UserAgent.h"
#include"RandomAgent.h"
#include"QAgent.h"
#include"OseloSystem.h"

#include<iostream>
#include<typeinfo>
#include<string>
#include<algorithm>

using namespace std;

//�R���X�g���N�^

//oselo��obj,my_color��color��ݒ�
BaseAgent::BaseAgent(const shared_ptr<OseloClass> &obj, const int &color)
	:oselo(obj), my_color(color) {}

//oselo��obj,my_color��color��ݒ�
UserAgent::UserAgent(const shared_ptr<OseloClass> &obj, const int &color)
	:BaseAgent(obj, color) {}

//oselo��obj,my_color��color��ݒ�
//putter��BoardSize�ŏ�����
RandomAgent::RandomAgent(const shared_ptr<OseloClass> &obj, const int &color)
	:BaseAgent(obj, color)
{
	this->putter_x = uniform_int_distribution<>(0, obj->GetBoard().GetBoardSize().x - 1);
	this->putter_y = uniform_int_distribution<>(0, obj->GetBoard().GetBoardSize().y - 1);
}

//��ԕ\��
void BaseAgent::DispTurn()
{
	const char *turn[] =
	{
		"BLACK",
		"WHITE",
	};

	cout << typeid(*this).name() << ":" << turn[this->my_color] << endl;
}

//Put

//���[�U���΂�u��
void UserAgent::Put()
{
	this->DispTurn();

	CellCoord coord;
	string temp;
	cout << "put x and y" << endl;
	cin >> coord.x >> temp;

	coord.y = temp.front() - 'a';

	while (!this->oselo->Put(coord))
	{
		cout << "error! once more!" << endl;

		cout << "put x and y" << endl;
		cin >> coord.x >> temp;
		coord.y = temp.front() - 'a';
	}
}

//�����_���ɐ΂�u��
void RandomAgent::Put()
{
	this->DispTurn();

	auto coords=OseloSystem::GetPutable(this->oselo->GetBoard(),this->my_color);
	shuffle(begin(coords), end(coords), this->mt);

	this->oselo->Put(coords.front());
}


