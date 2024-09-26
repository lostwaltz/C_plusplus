#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;
	int32 dir = _dir;

	_path.clear();
	_path.push_back(pos);

	Pos dest = board->GetExitPos();

	Pos front[4]
	{
		Pos { 0, -1 },
		Pos { -1, 0 },
		Pos { 0, 1 },
		Pos { 1, 0 },
	};

	while (pos != dest)
	{
		// Player 방향 기준 오른쪽 타일 검사, 방향전환과 이동
		int32 rotationRightDir = (dir - 1 + DIR_COUNT) % DIR_COUNT;
		int32 rotationLefttDir = (dir + 1) % DIR_COUNT;
		if (CanGO(pos + front[rotationRightDir]))
		{
			dir = rotationRightDir;
			pos += front[dir];
			_path.push_back(pos);
		}
		else if(CanGO(pos + front[dir]))
		{
			pos += front[dir];
			_path.push_back(pos);
		}
		else
		{
			dir = rotationLefttDir;
		}
	}
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGO(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}
