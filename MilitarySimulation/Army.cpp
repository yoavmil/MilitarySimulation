#include "Army.h"

Army::Army(Board* board, int id) :
	board(board),
	id(id), 
	remainingSoldiers(0)
{}

void Army::initSoldiers(int armySize)
{
	soldiers.resize(armySize, Soldier(board, this));
	remainingSoldiers = armySize;
}

void Army::turn()
{
	for (auto& soldier : soldiers) {
		soldier.shoot();
	}
	for (auto& soldier : soldiers) {
		soldier.move();
	}
}
