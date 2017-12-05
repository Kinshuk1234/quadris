#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include <memory> // For pointer to TextDisplay
#include "observer.h"
// #include "subject.h"
// #include "graphicsdisplay.h"
#include "cell.h"
#include "block.h"
#include "scoreboard.h"
#include "pos.h"
#include "gameboarddata.h"

class TextDisplay;

// class GraphicsDisplay;

class ScoreBoard;

class Level; // May need to change if changing from ptr to another ref to object.


// Observer of the Command Interpreter
// Subject to the displays
class GameBoard : public Observer<std::vector<std::string>> {
	bool lastWasHint = false;
	std::vector<std::vector<Cell>> grid; // List of rows in the grid containing each cell (r, c)
	int lastTurnScore; // score of the most recent turn, to be sent to the scoreboard
	Block *currentBlock;
	std::vector<Block *> blockList;
	Level *level;
	ScoreBoard scoreBoard;
	bool gameOver;
	Block *nextBlock;
	std::vector<Pos> hintPoints;
	TextDisplay *td;
	int seed;
	int starCount;
	// GraphicsDisplay * gd;
	bool bonusEnabled;

public:

	// TODO: SO MANY OF THESE METHODS CAN BE PRIVATE

	void init(); // public method 
	
	void notify(Subject<std::vector<std::string>> &notifier);

	void changeCell(int r, int c, char ch); // TEMP

	bool tryNewBlock(Block *blockToBePlaced = nullptr);
	void placeCurrentBlock();
	void updateGrid(std::vector<Pos> points, char letter);
	Cell &getCellAt(Pos p);
	void removeFullRows();
	void refreshBoard(); // TOOD: may not need if Cell doesn't use it's coords

	void restartGame();
	
	// hint method
	bool checkCoor(int row, int col, std::vector<Pos> currentBlockPoints);
	int totalEmptyRows(std::vector<Pos> currentBlockPoints);
	void bestPlace();

	// Big 5 + ctor
	GameBoard(TextDisplay *td /*, GraphicsDisplay *gd*/, int startLevel, int seed, std::string filename, bool bonusEnabled); //, GraphicsDisplay *gd);
	GameBoard(const GameBoard &other) = delete;
	GameBoard(GameBoard &&other) = delete;
	GameBoard &operator=(const GameBoard &other) = delete;
	GameBoard &operator=(GameBoard &&other) = delete;
	~GameBoard();

private:
	bool isFittable(const std::vector<Pos> &oldPoints, const std::vector<Pos> &currOrientation, const bool dropCheck); // TODO: make const, then make getCellAt const, then make Cell copy ctor, Subject copy ctor
	bool dropBlock(Block *b);
	void levelChange(bool goUp);

	void removeOldBlocks();
	void updateBlockTurnCounts();
};

#endif


