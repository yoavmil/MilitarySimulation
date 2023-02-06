#pragma once

#include "includes.h"
#include "using.h"
#include "Position.h"

class Board;
class Army;

class Soldier
{
public:
    Soldier(Board* board, Army* army) :board(board), army(army) {}
    int life = 100;
   
    Board* board;
    Army* army;
    
    Position position = { -1,-1 };
    void shoot(int maxDistance = 10, int damage = 50);
    void move(int maxDistance = 10);
    void recieveShot(int damage = 50);
};

