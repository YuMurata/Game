#pragma once

#include"BoardClass.h"

class OseloSystem
{
public:
	using Flip = std::vector<CellCoord>;

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
	static std::pair<PutState,PutState> Init(BoardClass *board);

	static PutState Put(BoardClass *board, const CellCoord &coord, const int &color);
	
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
	
	static std::vector<CellCoord> GetPutable(const BoardClass& board, const int &color);

	static int GetWin(const BoardClass &board);

//Undo,Redo

	static PutState Undo(BoardClass *board);

	static bool Redo(BoardClass *board);
};