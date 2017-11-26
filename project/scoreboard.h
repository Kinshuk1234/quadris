#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class GameBoard;

// ScoreBoard: To keep track of the current and highscore
class ScoreBoard {
	int currentScore;
	int highScore;
public:
	

	// Visitor of GameBoard
	void updateCurrentScoreWith(GameBoard &gb); // Start here
	void updateScore(int lastTurnScore);

	// Big 5 + ctor
	ScoreBoard();
	ScoreBoard(const ScoreBoard &other) = delete;
	ScoreBoard(ScoreBoard &&other) = delete;
	ScoreBoard &operator=(const ScoreBoard &other) = delete;
	ScoreBoard &operator=(ScoreBoard &&other) = delete;
};

#endif
