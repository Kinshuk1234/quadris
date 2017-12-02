#ifndef GAMEBOARDDATA_H
#define GAMEBOARDDATA_H

#include "cell.h"
#include <vector>

struct GameBoardData {
	std::vector<std::vector<Cell>> cells;
	bool gameOver;
	int currentLevel;
	int hiScore;
	int currentScore;
	// Any other data you may need
};

#endif

