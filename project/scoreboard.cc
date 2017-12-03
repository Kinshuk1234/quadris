#include "scoreboard.h"
#include "gameboard.h"

#include <iostream>

using namespace std;

// Big 5 + ctor ---------------------------------

ScoreBoard::ScoreBoard()
: currentLevel{0}, currentScore{0}, hiScore{0} {/* CTOR BODY */}

void ScoreBoard::updateCurrentScore(int lasTurnScore) {
	currentScore += lasTurnScore;
	if (currentScore > hiScore) {
		hiScore = currentScore;
	}
	notifyAll();
}

void ScoreBoard::updateLevel(int newLevel) {
	currentLevel = newLevel;
	notifyAll();
}

int ScoreBoard::getCurrentScore() {
	return currentScore;
}

int ScoreBoard::getHiScore() {
	return hiScore;
}

ScoreBoardData ScoreBoard::getData() {
	ScoreBoardData sbData;
	sbData.level = currentLevel;
	sbData.currentScore = currentScore;
	sbData.hiScore = hiScore;
	return sbData;
}
