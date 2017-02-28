// OseloSystem.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include"OseloClass.h"

#include"UserAgent.h"
#include"RandomAgent.h"
#include"QAgent.h"
#include"QLTLAgent.h"

using namespace std;

int main()
{
	shared_ptr<OseloClass> obj(new OseloClass(8, BoardClass::Cell_BLACK));

	unique_ptr<QAgent> black(new QAgent(obj, BoardClass::Cell_BLACK));
	unique_ptr<RandomAgent> white(new RandomAgent(obj, BoardClass::Cell_WHITE));

	//black->LoadFile("black.ql");
	//white->LoadFile("white.ql");

	unique_ptr<BaseAgent> agents[BoardClass::Cell_NUM];
	
	agents[black->GetColor()] = move(black);
	agents[white->GetColor()] = move(white);
	
	ofstream ofs("QAgent_win.xls");

	//int win_count[BoardClass::Cell_NUM+1] = { 0 };
	int win_count = 0;
	for (int i = 1; i <= 100; ++i)
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
		if (obj->GetWin() == BoardClass::Cell_BLACK)
		{
			++win_count;
		}
		ofs << i << "\t" << 1.*i / win_count << endl;
		cout << i << endl;

		BaseAgent::win = obj->GetWin();
		//++win_count[BaseAgent::win+1];
		
		PutState state;

		while ((state=obj->Undo()).IsPut())
		{
			agents[obj->GetCurrent()]->Review(state.put);
			obj->DrawBoard();
		}
		BaseAgent::win = BoardClass::Cell_Empty;
	}

	//dynamic_cast<QLTLAgent*>(agents[0].get())->WriteFile(("black.ql"));
	//dynamic_cast<QAgent*>(agents[1].get())->WriteFile(("white.ql"));

	//cout << win_count[BoardClass::Cell_BLACK+1] << ":" << win_count[BoardClass::Cell_WHITE+1] << ":" << win_count[BoardClass::Cell_Empty + 1]<< endl;

#ifndef NDEBUG
	_getch();
#endif // !NDEBUG


    return 0;
}