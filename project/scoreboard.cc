#include "scoreboard.h"
#include "gameboard.h"


ScoreBoard::ScoreBoard()
: currentScore{0}, highScore{0} {/* CTOR BODY */}


void ScoreBoard::updateScore(int lastTurnScore) {
	currentScore += lastTurnScore;
	if (currentScore >= highScore) {
		highScore = currentScore;
	}
}

void ScoreBoard::updateCurrentScoreWith(GameBoard &gb) {
	gb.updateScore(*this);
}

