#include"stdafx.h"

#include"BoardClass.h"

using namespace std;

//���Wcoord�ɐFcolor��ݒ�
void BoardClass::PutPiecesAt(const PutState &state)
{
	const int &color = state.color;

	this->PutPieceAt(state.put, color);
	
	for (auto &i : state.flip)
	{
		this->PutPieceAt(i, color);
	}

	this->undo.push(state);

	if (!this->redo.empty())
	{
		this->redo = stack<PutState>();
	}
}
