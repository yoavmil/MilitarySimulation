#include "includes.h"
#include "using.h"

#include "GamePlay.h"

#define DEFAULT_ARMY_SIZE 20
#define DEFUALT_BOARD_SIZE 100

int main(int argc, char** argv) {
	int armySize = DEFAULT_ARMY_SIZE;

	if (argc > 1) {
		if (string(argv[1]) == "--help") {
			cout << "usage: ArmySim.exe [${army_size}]\n";
			cout << "\t(default army size is " << DEFAULT_ARMY_SIZE << "\n";
			return 0;
		}

		armySize = std::stoi(argv[1]);

		// TODO check user input, > 0, < 100*100

	}

	GamePlay game(armySize, DEFUALT_BOARD_SIZE);
	game.loop(50);
	
	return 0;
}