// OseloSystem.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"

#include"OseloClass.h"
#include"UserAgent.h"
#include"RandomAgent.h"
#include"QAgent.h"

#include<iostream>
#include<conio.h>


using namespace std;

int main()
{
	shared_ptr<OseloClass> obj(new OseloClass(8, BoardClass::Cell_BLACK));

	unique_ptr<QAgent> black(new QAgent(obj, BoardClass::Cell_BLACK));
	unique_ptr<QAgent> white(new QAgent(obj, BoardClass::Cell_WHITE));


	black->LoadFile("black.ql");
	white->LoadFile("white.ql");

	unique_ptr<BaseAgent> agents[BoardClass::Cell_NUM];
	
	agents[black->GetColor()] = move(black);
	agents[white->GetColor()] = move(white);
	

	for (int i = 0; i < 100; ++i)
	{
		obj->Init();
		obj->DrawBoard();

		while (!obj->CheckFinish())
		{

			agents[obj->GetCurrent()]->Put();

			obj->ChangeTurn();
			if (!obj->CheckPutable())
			{
				obj->ChangeTurn();
			}

			obj->DrawBoard();
		}

		cout << i << endl;
	}

	dynamic_cast<QAgent*>(agents[0].get())->WriteFile(("black.ql"));
	dynamic_cast<QAgent*>(agents[1].get())->WriteFile(("white.ql"));

	_getch();

    return 0;
}

