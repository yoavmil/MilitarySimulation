#pragma once

#include "includes.h"
#include "using.h"
#include "Position.h"

class Army;

class Soldier
{
public:
    Soldier(Army* army) : army(army) {}
    int life = 100;
    Army* army;
    Position position = { -1,-1 };
    void shoot();
    void move();
};

