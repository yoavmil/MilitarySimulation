#include "Board.h"
#include "Soldier.h"
#include "Army.h"

Board::Board(int size) :
	grid((size_t)size, { (size_t)size, nullptr })
{}

void Board::print()
{
	for (size_t y = 0; y < grid.size(); y++) {
		auto& row = grid[y];
		for (size_t x = 0; x < row.size(); x++) {
			Soldier* soldier = grid[y][x];
			if (soldier == nullptr)
				cout << "#";
			else if (soldier->life == 0)
				cout << "X";
			else 
				cout << soldier->army->id;
		}
		cout << "\n";
	}
	cout << "\n";
}
