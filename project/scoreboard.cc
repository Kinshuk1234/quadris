#include "scoreboard.h"
#include "gameboard.h"

// other methods ---------------------------------


void ScoreBoard::updateScore(int lastTurnScore) {
	currentScore += lastTurnScore;
	if (currentScore >= highScore) {
		highScore = currentScore;
	}
}

void ScoreBoard::updateCurrentScoreWith(GameBoard &gb) {
	gb.updateScore(*this);
}


// Big 5 + ctor ---------------------------------

ScoreBoard::ScoreBoard()
: currentScore{0}, highScore{0} {/* CTOR BODY */}

