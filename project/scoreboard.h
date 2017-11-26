#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class GameBoard;

// ScoreBoard: To keep track of the current and highscore
class ScoreBoard {
	int currentScore;
	int highScore;
public:
	ScoreBoard();

	// Visitor of GameBoard
	void updateCurrentScoreWith(GameBoard &gb); // Start here
	void updateScore(int lastTurnScore);
};

#endif
