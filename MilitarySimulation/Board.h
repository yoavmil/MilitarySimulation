#pragma once

#include "includes.h"
#include "using.h"

class Soldier;

class Board
{
public:
	Board(int size = 100);
	vector<vector<Soldier*>> grid;
	void print();
};

