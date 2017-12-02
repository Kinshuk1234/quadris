#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class GameBoard;

// ScoreBoard: To keep track of the current and highscore
class ScoreBoard {
	int currentScore;
	int hiScore;
public:
	

	// Visitor of GameBoard
	void updateScore(int lastTurnScore);
	int getCurrentScore();
	int getHiScore();

	// Big 5 + ctor
	ScoreBoard();
	ScoreBoard(const ScoreBoard &other) = delete;
	ScoreBoard(ScoreBoard &&other) = delete;
	ScoreBoard &operator=(const ScoreBoard &other) = delete;
	ScoreBoard &operator=(ScoreBoard &&other) = delete;
};

#endif
