#include "gameboard.h"
#include "scoreboard.h"

GameBoard::GameBoard()
:lastTurnScore{0} {/* CTOR BODY */}



void GameBoard::updateScore(ScoreBoard &sb) {
	sb.updateScore(lastTurnScore);
}


