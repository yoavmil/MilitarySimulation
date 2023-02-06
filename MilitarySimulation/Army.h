#pragma once

#include "includes.h"
#include "using.h"
#include "Soldier.h"

class Board;

class Army
{
public:
    Army(Board* board, int id);
    Board* board;
    void initSoldiers(int armySize);
    vector<Soldier> soldiers;
    int remainingSoldiers;
    void turn();
    int id;
};
