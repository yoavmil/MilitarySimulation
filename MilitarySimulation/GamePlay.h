#pragma once

#include "includes.h"
#include "using.h"
#include "Army.h"
#include "Board.h"

class GamePlay
{
public:
    GamePlay(int armySize, int boardSize);
    vector<Army> armies;
    Board board;
    void loop(int turns);
    bool checkVictory();

protected:
    void initArmies(int size);
    void initSoldiersPositions();
    int armySize, boardSize;
};

