#include "Army.h"

Army::Army(int id, int armySize) :
	id(id),
	soldiers(armySize, Soldier(this)),
	remainingSoldiers(armySize)
{}
