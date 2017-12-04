#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "scoreboarddata.h"
#include "subject.h"

class GameBoard;

// ScoreBoard: To keep track of the current and highscore
class ScoreBoard : public Subject<ScoreBoardData> {
	int currentLevel;
	int currentScore;
	int hiScore;
	char nextBlockLetter;
public:
	
	ScoreBoardData getData() override;

	// Visitor of GameBoard
	void updateScore(int lastTurnScore);
	void updateLevel(int newLevel);
	int getCurrentScore();
	int getHiScore();
	void updateCurrentScore(int lastTurnScore);
	void setCurrentScore(int newScore);
	void updateNextBlock(char nextBlockLetter);

	// Big 5 + ctor
	ScoreBoard();
	ScoreBoard(const ScoreBoard &other) = delete;
	ScoreBoard(ScoreBoard &&other) = delete;
	ScoreBoard &operator=(const ScoreBoard &other) = delete;
	ScoreBoard &operator=(ScoreBoard &&other) = delete;
};

#endif
