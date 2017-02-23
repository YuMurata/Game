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

//コンストラクタ

//oseloにobj,my_colorにcolorを設定
BaseAgent::BaseAgent(const shared_ptr<OseloClass> &obj, const int &color)
	:oselo(obj), my_color(color) {}

//oseloにobj,my_colorにcolorを設定
UserAgent::UserAgent(const shared_ptr<OseloClass> &obj, const int &color)
	:BaseAgent(obj, color) {}

//oseloにobj,my_colorにcolorを設定
//putterをBoardSizeで初期化
RandomAgent::RandomAgent(const shared_ptr<OseloClass> &obj, const int &color)
	:BaseAgent(obj, color)
{
	this->putter_x = uniform_int_distribution<>(0, obj->GetBoard().GetBoardSize().x - 1);
	this->putter_y = uniform_int_distribution<>(0, obj->GetBoard().GetBoardSize().y - 1);
}

//手番表示
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

//ユーザが石を置く
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

//ランダムに石を置く
void RandomAgent::Put()
{
	this->DispTurn();

	auto coords=OseloSystem::GetPutable(this->oselo->GetBoard(),this->my_color);
	shuffle(begin(coords), end(coords), this->mt);

	this->oselo->Put(coords.front());
}


