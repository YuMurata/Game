#include"UserAgent.h"
#include"RandomAgent.h"
#include"OseloSystem.h"
#include<iostream>

using namespace std;

void UserAgent::Put()
{
	this->DispTurn();

	CellCoord coord;
	cout << "put x y" << endl;
	cin >> coord.x >> coord.y;
	coord.y -= 'a';

	while (!this->oselo->Put(coord).IsPut())
	{
		cout << "put error! try again!" << endl;
		cout << "put x y" << endl;
		cin >> coord.x >> coord.y;
		coord.y -= 'a';
	}
}

void RandomAgent::Put()
{
	this->DispTurn();

	auto as = OseloSystem::GetPutable(this->oselo->GetBoard(), this->my_color);

	shuffle(begin(as), end(as), this->mt);

	this->oselo->Put(as.front());
}