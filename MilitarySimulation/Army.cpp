#include "Army.h"

Army::Army(int id) :
	id(id)
{}

void Army::initSoldiers(int armySize)
{
	soldiers.resize(armySize, Soldier(this));
	remainingSoldiers = armySize;

}
