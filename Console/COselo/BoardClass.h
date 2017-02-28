#pragma once

#include"stdafx.h"

#include<Coordinate.h>
#include<vector>
#include<iostream>
#include<utility>
#include<stack>

#include"PutState.h"

typedef TCoordinate<int> CellNum;
typedef TCoordinate<int> CellCoord;

using Board = std::vector<std::vector<int>>;
using State = std::vector<std::pair<CellCoord, int>>;

class BoardClass
{
private:
	std::vector<std::vector<int>> board;//�Ֆ�
	CellNum board_size;//�Ֆʂ̃T�C�Y
	std::vector<int> cell_num;

	std::stack<PutState> undo;
	std::stack<PutState> redo;

	void PutPieceAt(const CellCoord &coord, const int &color)
	{
		auto &cell = this->board[coord.y][coord.x];

		if (color != Cell_Empty)
		{
			if (cell != Cell_Empty)
			{
				--this->cell_num[(color + 1) % 2];
			}

			++this->cell_num[color];
		}

		cell = color;
	}

public:
	//�}�X�ڂ̏��
	enum CellState
	{
		Cell_Empty=-1,
		Cell_BLACK,
		Cell_WHITE,
		Cell_NUM,
	};

//Init

	BoardClass() :BoardClass(8) {}

	//cell_num��cell_num��ݒ�
	BoardClass(const CellNum &board_size);

	//�Ֆʂ̏�����
	std::pair<PutState,PutState> Init();

//Put

	//���Wcoord�ɐFcolor��ݒ�
	void PutPiecesAt(const PutState &state);

//Get

	//�Ֆʂ̑傫�����擾
	CellNum GetBoardSize()const;

	//���Wcoord�̏�Ԃ��擾
	int GetCellState(const CellCoord &coord)const;

	//�Fcolor�̐ΐ����擾
	int GetCellNum(const int &color)const;

	//�����ق��̐F���擾
	int GetOften()const;

	Board GetBoard()const;

	bool operator==(const BoardClass &obj)const
	{
		return this->board == obj.board;
	}

	bool operator<(const BoardClass &obj)const
	{
		return this->board < obj.board;
	}

	friend std::ostream& operator<<(std::ostream&, const BoardClass&);

	BoardClass& operator=(const std::vector<std::vector<int>> &input)
	{
		this->board = input;
		this->board_size = CellNum(size(input[0]), size(input));

		return *this;
	}

	PutState Undo()
	{
		if (this->undo.empty())
		{
			return PutState();
		}
		
		PutState state = this->undo.top();

		this->PutPieceAt(state.put, Cell_Empty);

		const int &enemy_color = (state.color+1)%2;
		
		for (auto &i : state.flip)
		{
			this->PutPieceAt(i, enemy_color);
		}

		this->redo.push(state);
		this->undo.pop();

		return state;
	}

	bool Redo()
	{
		if (this->redo.empty())
		{
			return false;
		}

		PutState state = this->redo.top();

		const int &color = state.color;
		
		this->PutPieceAt(state.put, color);


		for (auto &i : state.flip)
		{
			this->PutPieceAt(i, color);
		}

		this->undo.push(state);
		this->redo.pop();

		return true;
	}
};