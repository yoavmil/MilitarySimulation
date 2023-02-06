#include "GamePlay.h"

GamePlay::GamePlay(int armySize, int boardSize):
	board(boardSize)
{
	initArmies(armySize);

}

void GamePlay::initArmies(int size)
{
	armies.push_back(Army((int)armies.size(), size));
	armies.push_back(Army((int)armies.size(), size));
}
