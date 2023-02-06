#include "GamePlay.h"

GamePlay::GamePlay(int armySize, int boardSize):
	armySize(armySize),
	boardSize(boardSize),
	board(boardSize)
{
	initArmies(armySize);
	initSoldiersPositions();
}

void GamePlay::loop(int turns)
{
	for (int turn = 0; turn < turns && !checkVictory(); turn++) {
		armies[turn % armies.size()].turn();
		board.print();
		// system("pause");
	}
}

bool GamePlay::checkVictory()
{
	return std::any_of(armies.begin(), armies.end(), [](const Army& army) {
		return army.remainingSoldiers == 0;
		});
}

void GamePlay::initArmies(int size)
{
	armies.push_back(Army(&board, (int)armies.size()));
	armies.push_back(Army(&board, (int)armies.size()));
	for (auto& army : armies) 
		army.initSoldiers(armySize);
}

void GamePlay::initSoldiersPositions()
{
	// create a vector of all possible positions, then
	// shuffle it, and place the soldiers

	vector<Position> positions;
	for (int x = 0; x < boardSize; x++) {
		for (int y = 0; y < boardSize; y++) {
			positions.push_back({ x,y });
		}
	}

	std::random_shuffle(positions.begin(), positions.end());

	for (int i = 0; i < armySize; i++) {
		armies[0].soldiers[i].position = positions[i * 2 + 0];
		armies[1].soldiers[i].position = positions[i * 2 + 1];
	}
	for (auto& army : armies) {
		for (auto& soldier : army.soldiers) {
			const auto& pos = soldier.position;
			board.grid[pos.y][pos.x] = &soldier;
		}
	}
}
