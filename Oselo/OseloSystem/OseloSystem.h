#pragma once

#include"stdafx.h"

#include"BoardClass.h"

#include<utility>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class OseloSystem
{
public:
	using Flip = vector<CellCoord>;

public:
//Check

	//���W[x,y]���Ֆʂ̒��Ȃ�true
	static bool CheckInside(const BoardClass &board, const CellCoord &coord);

	//�꒼����ɗ��Ԃ�����̂�������true
	//�����Ԃ�����W[x,y]��flip_piece�Ɋi�[
	static bool CheckLine(const BoardClass &board, const CellCoord &coord, const CellCoord &dcoord, const int &color, Flip *flip_piece);

	//�אڂ���Z�������ɗ��Ԃ�����̂���������true
	//�����Ԃ�����W[x,y]��flip_piece�Ɋi�[
	static bool CheckSide(const BoardClass &board, const CellCoord &coord, const int &color, Flip *flip_piece);

	//���W[x,y]�ɐ΂��z�u����Ă��Ȃ����true
	static bool CheckNone(const BoardClass &board, const CellCoord &coord);

	//���W[x,y]�ɐ΂��z�u����Ă��Ȃ��A�����W[x,y]�̗אڕ����ɗ��Ԃ�����̂������true
	static bool CheckPut(const BoardClass &board, const CellCoord &coord, const int &color, Flip *flip_piece);

	//�Ֆʂɐ΂�z�u�ł�����W�������true
	static bool CheckPutable(const BoardClass &board, const int &color);

	//�΂�z�u�ł���ꏊ���Ȃ��A�������͔z�u���ꂽ�΂̑������Ֆʂ̃T�C�Y�Ɠ��������true
	static bool CheckFinish(const BoardClass &board);

//Put,Init

	//�Ֆʂ̒����ɐ΂�z�u
	static void Init(BoardClass *board);

	static bool Put(BoardClass *board, const CellCoord &coord, const int &color);
	
//Disp

	//�Ֆʂ̕`��
	static void DrawBoard(const BoardClass &board);

	//�΂̐���\��
	static void DispCells(const int &black_count, const int &white_count);

	//�΂�z�u�ł��Ȃ��ꍇ�ɌĂяo��
	static void Pass(const int &color);

//ETC

	//turn_color�̔��]
	static void ChangeTurn(int *turn_color);

//Get

	static BoardClass GetEstimate(const BoardClass &board, const CellCoord &coord, const int &color);
	
	static vector<CellCoord> GetPutable(const BoardClass& board, const int &color);

//Undo,Redo

	static bool Undo(BoardClass *board);

	static bool Redo(BoardClass *board);
};