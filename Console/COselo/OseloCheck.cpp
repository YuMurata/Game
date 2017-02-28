#include"OseloImpl.h"
#include"OseloSystem.h"

//�Ֆʂɐ΂�z�u�ł�����W�������true
bool OseloClass::CheckPutable()const
{
	return OseloSystem::CheckPutable(this->pimpl->board, this->pimpl->current_turn);
}

//�΂�z�u�ł���ꏊ���Ȃ��A�������͔z�u���ꂽ�΂̑������Ֆʂ̃T�C�Y�Ɠ��������true
bool OseloClass::CheckFinish()const
{
	return OseloSystem::CheckFinish(this->pimpl->board);
}

//���W[x,y]���Ֆʂ̒��Ȃ�true
bool OseloSystem::CheckInside(const BoardClass &board, const CellCoord &coord)
{
	bool flag = (CellCoord)0 <= coord&&coord < board.GetBoardSize();

	return flag;
}

//�꒼����ɗ��Ԃ�����̂�������true
//�����Ԃ�����W[x,y]��flip_piece�Ɋi�[
bool OseloSystem::CheckLine(const BoardClass &board, const CellCoord &coord, const CellCoord &dcoord, const int &color, Flip *flip_piece)
{
	const int enemy_color = (color + 1) % 2;

	auto sum_coord = coord + dcoord;

	if (!CheckInside(board, sum_coord))
	{
		return false;
	}

	if (board.GetCellState(sum_coord) == color)
	{
		flip_piece->push_back(coord);
		return true;
	}
	else if (board.GetCellState(sum_coord) == enemy_color)
	{
		bool line_flag = CheckLine(board, sum_coord, dcoord, color, flip_piece);
		if (line_flag)
		{
			flip_piece->push_back(coord);
		}
		return line_flag;
	}
	else
	{
		return false;
	}
}

//�אڂ���Z�������ɗ��Ԃ�����̂���������true
//�����Ԃ�����W[x,y]��flip_piece�Ɋi�[
bool OseloSystem::CheckSide(const BoardClass &board, const CellCoord &coord, const int &color, Flip *flip_piece)
{
	const int UP = -1;
	const int DOWN = 1;
	const int LEFT = -1;
	const int RIGHT = 1;

	const int enemy_color = (color + 1) % 2;
	bool putable_flag = false;

	for (int dy = UP; dy <= DOWN; ++dy)
	{
		if (!CheckInside(board, CellCoord(coord.x, coord.y + dy)))
		{
			continue;
		}

		for (int dx = LEFT; dx <= RIGHT; ++dx)
		{
			auto dcoord = CellCoord(dx, dy);
			auto sum_coord = coord + dcoord;
			if (!CheckInside(board, sum_coord))
			{
				continue;
			}

			if (board.GetCellState(sum_coord) == enemy_color)
			{
				if (CheckLine(board, sum_coord, dcoord, color, flip_piece))
				{
					putable_flag = true;
				}
			}
		}
	}
	return putable_flag;
}

//���W[x,y]�ɐ΂��z�u����Ă��Ȃ����true
bool OseloSystem::CheckNone(const BoardClass &board, const CellCoord &coord)
{
	return board.GetCellState(coord) == BoardClass::Cell_Empty;
}

//���W[x,y]�ɐ΂��z�u����Ă��Ȃ��A�����W[x,y]�̗אڕ����ɗ��Ԃ�����̂������true
bool OseloSystem::CheckPut(const BoardClass &board, const CellCoord &coord, const int &color, Flip *flip_piece)
{
	return CheckInside(board, coord) && CheckNone(board, coord) && CheckSide(board, coord, color, flip_piece);
}

//�Ֆʂɐ΂�z�u�ł�����W�������true
bool OseloSystem::CheckPutable(const BoardClass &board, const int &color)
{
	return !GetPutable(board, color).empty();
}

//�΂�z�u�ł���ꏊ���Ȃ��A�������͔z�u���ꂽ�΂̑������Ֆʂ̃T�C�Y�Ɠ��������true
bool OseloSystem::CheckFinish(const BoardClass &board)
{
	bool putable_flag = false;

	for (int i = BoardClass::Cell_BLACK; i <= BoardClass::Cell_WHITE; ++i)
	{
		if (CheckPutable(board, i))
		{
			putable_flag = true;
		}
	}

	return !putable_flag;
}