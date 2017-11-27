#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include "row.h"
#include <memory> // For pointer to TextDisplay

class TextDisplay;

class ScoreBoard;

class GameBoard {
	std::vector<Row> rowList; // List of rows in the grid containing each cell (r, c)
	int lastTurnScore; // score of the most recent turn, to be sent to the scoreboard

public:

	// Visitor pattern with ScoreBoard
	void updateScore(ScoreBoard &sb);

	// Big 5 + ctor
	GameBoard(std::unique_ptr<TextDisplay> &td);
	GameBoard(const GameBoard &other) = delete;
	GameBoard(GameBoard &&other) = delete;
	GameBoard &operator=(const GameBoard &other) = delete;
	GameBoard &operator=(GameBoard &&other) = delete;
};

#endif


