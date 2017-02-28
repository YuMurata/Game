#pragma once

#include"PutState.h"

class BoardClass
{
public:
using CellNum = TCoordinate<int>;

using Board = std::vector<std::vector<int>>;
using State = std::vector<std::pair<CellCoord, int>>;

private:
	class Impl;
	std::unique_ptr<Impl> pimpl;

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

	BoardClass();

	//cell_num��cell_num��ݒ�
	BoardClass(const CellNum &board_size);

	BoardClass(const BoardClass &board);

	~BoardClass();

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

	bool operator==(const BoardClass &obj)const;

	bool operator<(const BoardClass &obj)const;

	friend std::ostream& operator<<(std::ostream&, const BoardClass&);

	BoardClass& operator=(const std::vector<std::vector<int>> &input);

	BoardClass& operator=(const BoardClass &board);

	PutState Undo();

	bool Redo();
};