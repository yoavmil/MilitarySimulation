#include "Soldier.h"
#include "Army.h"
#include "Board.h"

void Soldier::shoot(int maxDistance, int damage)
{
	if (life <= 0) return;
	enum Dir {
		N, // up, Y-
		E, // right, X+
		S, // down, Y+
		W, // left, X-
		DIR_MAX
	};
	vector<bool> blocked(DIR_MAX, false);

	auto checkTarget = [&](Position target, Dir dir) -> bool {
		auto other = board->grid[target.y][target.x];
		if (other != nullptr && other->life > 0) {
			if (other->army->id != this->army->id) {
				other->recieveShot(damage);
				return true;
			}
			if (other->army->id == this->army->id)
				blocked[dir] = true;
		}
		return false;
	};

	for (int dist = 1; dist <= maxDistance; dist++) {
		// check each direction by enum order
		auto dir = N;
		if (!blocked[dir] && position.y - dist >= 0) {
			Position target = { position.x, position.y - dist };
			if (checkTarget(target, dir)) break;
		}

		dir = N;
		if (!blocked[dir] && position.x + dist < board->grid.size()) {
			Position target = { position.x + dist, position.y };
			if (checkTarget(target, dir)) break;
		}

		dir = S;
		if (!blocked[dir] && position.y + dist < board->grid.size()) {
			Position target = { position.x, position.y + dist };
			if (checkTarget(target, dir)) break;
		}

		dir = W;
		if (!blocked[dir] && position.x - dist >= 0) {
			Position target = { position.x - dist, position.y };
			if (checkTarget(target, dir)) break;
		}
	}
}

void Soldier::move(int maxDistance)
{
	// strategy - move away from enemies so they cannot shoot me

	auto shootingDistance = maxDistance; // asumed

	auto inBounds = [&](Position& pos) -> bool {
		return pos.x >= 0 && pos.y >= 0 && pos.x < board->grid.size() && pos.y < board->grid.size();
	};

	auto canBeShotFrom = [&](Position& pos) -> bool {
		if (!inBounds(pos)) return false;
		if (board->grid[pos.y][pos.x] == nullptr) return false;
		if (board->grid[pos.y][pos.x]->army != this->army) return true;
		return false;
	};

	auto isInEnemySight = [&](Position& pos) -> bool {
		// check N, up, Y-
		for (int d = 0; d < shootingDistance; d++) {
			Position pos = { position.x, position.y - d };
			if (canBeShotFrom(pos)) return true;
		}

		for (int d = 0; d < shootingDistance; d++) {
			Position pos = { position.x+d, position.y };
			if (canBeShotFrom(pos)) return true;
		}

		for (int d = 0; d < shootingDistance; d++) {
			Position pos = { position.x, position.y + d };
			if (canBeShotFrom(pos)) return true;
		}

		for (int d = 0; d < shootingDistance; d++) {
			Position pos = { position.x-d, position.y };
			if (canBeShotFrom(pos)) return true;
		}

		return false;
	};

	auto isClear = [&](Position& pos) -> bool {
		return inBounds(pos) && board->grid[pos.y][pos.x] == nullptr;
	};

	bool moved = false;

	auto moveTo = [&](Position& target) {
		board->grid[position.y][position.x] = nullptr;
		position = target;
		board->grid[position.y][position.x] = this;
		moved = true;
	};

	if (!isInEnemySight(position)) return;
	
	for (int dist = 1; dist < maxDistance && !moved; dist++) {
		Position target = { position.x, position.y - dist };
		if (inBounds(target) && !isInEnemySight(target) && isClear(target)) moveTo(target);
	}

	for (int dist = 1; dist < maxDistance && !moved; dist++) {
		Position target = { position.x+dist, position.y };
		if (inBounds(target) && !isInEnemySight(target) && isClear(target)) moveTo(target);
	}

	for (int dist = 1; dist < maxDistance && !moved; dist++) {
		Position target = { position.x, position.y + dist };
		if (inBounds(target) && !isInEnemySight(target) && isClear(target)) moveTo(target);
	}

	for (int dist = 1; dist < maxDistance && !moved; dist++) {
		Position target = { position.x - dist, position.y };
		if (inBounds(target) && !isInEnemySight(target) && isClear(target)) moveTo(target);
	}
}

void Soldier::recieveShot(int damage)
{
	if (life <= 0) return; // not supposed to happen
	life -= damage;
	if (life <= 0) {
		life = 0;
		army->remainingSoldiers--;
	}
}
