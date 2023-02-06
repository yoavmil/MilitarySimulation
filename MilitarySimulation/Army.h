#pragma once

#include "includes.h"
#include "using.h"
#include "Soldier.h"

class Army
{
public:
    
    Army(int id);
    void initSoldiers(int armySize);
    vector<Soldier> soldiers;
    int remainingSoldiers;
    void turn();
    int id;
};

