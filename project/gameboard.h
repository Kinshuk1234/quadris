#ifndef GAME_BOARD_H
#define GAME_BOARD_H

class ScoreBoard;

class GameBoard {
	int lastTurnScore; // score of the most recent turn, to be sent to the scoreboard

public:
	GameBoard();

	// Visitor pattern with ScoreBoard
	void updateScore(ScoreBoard &sb);
};

#endif


