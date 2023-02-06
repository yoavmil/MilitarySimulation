#pragma once

#include "includes.h"
#include "using.h"
#include "Soldier.h"

class Army
{
public:
    
    Army(int id, int armySize);
    vector<Soldier> soldiers;
    int remainingSoldiers;
    void turn();
    int id;
};

