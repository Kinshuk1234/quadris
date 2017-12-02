#include "scoreboard.h"
#include "gameboard.h"

// Big 5 + ctor ---------------------------------

ScoreBoard::ScoreBoard()
: currentScore{0}, hiScore{0} {/* CTOR BODY */}



int ScoreBoard::getCurrentScore() {
	return currentScore;
}

int ScoreBoard::getHiScore() {
	return hiScore;
}

