#include"stdafx.h"

#include"Hash.h"

#include"QAgent.h"
#include"OseloSystem.h"
#include<StringPlus.h>


QAgent::QAgent(const shared_ptr<OseloClass> &obj, const int &color,const bool &learn_flag)
	:BaseAgent(obj, color),learn_flag(learn_flag)
{
	using QL = QLClass<BoardClass, CellCoord>;
	
	using S = BoardClass;
	using A = CellCoord;

	using SA = QL::SA;
	using SAQ = QL::SAQ;

	using QTable = QL::QTable;

	auto func_r = [&](const BoardClass &s)
	{
		double reward = 0;
		
		if (OseloSystem::CheckFinish(s))
		{
			auto win = s.GetOften();
			if (win == this->my_color)
			{
				reward = 10;
			}
			else if (win == BoardClass::Cell_Empty)
			{
				reward = 0;
			}
			else
			{
				reward = -10;
			}
		}

		return reward;
	};

	auto func_t = [&](const BoardClass &s, const CellCoord &a)
	{
		return OseloSystem::GetEstimate(s,a,this->my_color);
	};
	
	auto func_as = [&](const BoardClass &s)
	{
		return OseloSystem::GetPutable(s,this->my_color);
	};

	auto func_load = [&](const vector<vector<string>> &data_list)
	{
		vector<SAQ> ret(size(data_list));

		auto board_size = this->oselo->GetBoard().GetBoardSize();

		auto s_size = board_size.x*board_size.y;
		auto a_size = 2;

		auto func = [&board_size,a_size](const vector<string> &input)
		{
			SAQ ret;
			auto &s = ret.first.first;
			auto &a = ret.first.second;
			auto &q = ret.second;

			auto itr = begin(input);


			vector<vector<int>> board(board_size.y);

			auto ret_board = [](const vector<string> &str)
			{
				vector<int> ret(size(str));

				transform(begin(str), end(str), begin(ret), [](const string &str) {return stoi(str); });
				return ret;
			};

			for (int y = 0; y < board_size.y; ++y)
			{
			auto last = itr + board_size.x;
				board[y] = ret_board(vector<string>(itr, last));

				itr = last;
			}

			s = board;

			a = CellCoord(stoi(*itr), stoi(*(itr + 1)));

			itr += a_size;

			q = stod(*itr);

			return ret;
		};

		transform(begin(data_list), end(data_list), begin(ret), func);

		return ret;
	};

	auto func_write = [](const QTable &q_table)
	{
		string s;
		string a;
		string q;

		vector<vector<string>> ret(size(q_table));

		auto func = [](const pair<SA, double> &saq)
		{
			stringstream is;
			is << saq.first.first << saq.first.second << saq.second;

			auto input = is.str();
			auto ret = SplitA(input);

			return ret;
		};

		transform(begin(q_table), end(q_table), begin(ret), func);

		return ret;
	};



	this->ql_obj.SetFunc(func_r, func_t, func_as,func_load,func_write);
}

void QAgent::Put()
{
	this->DispTurn();

	auto s = this->oselo->GetBoard();
	
	auto a=this->ql_obj.Learn(s);
	if (!this->learn_flag)
	{
		a = this->ql_obj.BestAction(s);
	}
	this->oselo->Put(a);
}