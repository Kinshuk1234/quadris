#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include <memory> // For pointer to TextDisplay
#include "observer.h"
#include "subject.h"
#include "cell.h"
#include "block.h"

class TextDisplay;

class ScoreBoard;

class Level; // May need to change if changing from ptr to another ref to object.


class GameBoard : public Observer<std::vector<std::string>> {
	std::vector<std::vector<Cell>> grid; // List of rows in the grid containing each cell (r, c)
	int lastTurnScore; // score of the most recent turn, to be sent to the scoreboard
	Block *currentBlock;
	std::vector<Block *> blockList;
	Level *level;

public:

	void notify(Subject<std::vector<std::string>> &notifier);

	void changeCell(int r, int c, char ch); // TEMP

	void setCurrentBlock(Block *b);

	// Visitor pattern with ScoreBoard
	void updateScore(ScoreBoard &sb);

	// Big 5 + ctor
	GameBoard(TextDisplay *td);
	GameBoard(const GameBoard &other) = delete;
	GameBoard(GameBoard &&other) = delete;
	GameBoard &operator=(const GameBoard &other) = delete;
	GameBoard &operator=(GameBoard &&other) = delete;
	~GameBoard();

private:
	void dropBlock();
	void moveX(bool goLeft); // if goLeft, then goes left, else goes right
	void moveY(); // TODO: amount can only be positive!
	void rotate(bool isClockwise);
	void levelChange(bool goUp);
};

#endif


