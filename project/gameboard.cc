#include <memory>
#include "gameboard.h"
#include "scoreboard.h"
#include "textdisplay.h"
// #include "graphicsdisplay.h"
#include <iostream>
#include "level0.h"
#include "level1.h"
#include "blockl.h"
#include "blocki.h"
#include "blockj.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"

#include "pos.h"

using namespace std;


void GameBoard::notify(Subject<vector<string>> &notifier) {
	vector<string> arr = notifier.getData();

	int xChange = 0, yChange = 0, rotateChange = 0;
	int transformedOr = currentBlock->getCurrentOr();
	Pos transformedRefPoint = currentBlock->getRefPoint(transformedOr);
	vector<Pos> initialPoints = currentBlock->getOrPtsOf(transformedRefPoint, transformedOr);

	for (auto it = arr.begin(); it != arr.end(); ++it) {
		string currCommand = *it;
		if (currCommand == "left") {
			xChange -= 1;
			yChange += (currentBlock->getIsHeavy() ? 1 : 0);
		} else if (currCommand == "right") {
			xChange += 1;
			yChange += (currentBlock->getIsHeavy() ? 1 : 0);
		} else if (currCommand == "down") {
			yChange += 1;
		} else if (currCommand == "clockwise") {
			rotateChange += 1;
			yChange += (currentBlock->getIsHeavy() ? 1 : 0);
		} else if (currCommand == "counterclockwise") {
			rotateChange = rotateChange + 4 - 1;
			yChange += (currentBlock->getIsHeavy() ? 1 : 0);
		} else if (currCommand == "drop") {
			Pos change = {xChange, yChange};
			transformedRefPoint = transformedRefPoint + change;
			transformedOr = (transformedOr + rotateChange) % 4; 
			vector<Pos> transformedPoints = currentBlock->getOrPtsOf(transformedRefPoint, transformedOr);
			if (isFittable(initialPoints, transformedPoints, false)) {
				blockList.emplace_back(currentBlock);
				dropBlock();
				if (gameOver) {
					currentBlock = nullptr;
					break;
				}
				xChange = 0;
				yChange = 0;
				rotateChange = 0;
				if (!tryNewBlock()) {
					cout << "TODO: Game Over" << endl;
				} else {
					transformedRefPoint = currentBlock->getRefPoint(currentBlock->getCurrentOr());
					transformedOr = currentBlock->getCurrentOr();
					initialPoints = currentBlock->getOrPtsOf(transformedRefPoint, transformedOr);
				}
			} else {
				// Invalid position
			}
		} else if (currCommand == "levelup") {
			// TODO: level up.
		} else if (currCommand == "I"
				 or currCommand == "J"
				 or currCommand == "L"
				 or currCommand == "O"
				 or currCommand == "S"
				 or currCommand == "T"
				 or currCommand == "Z") {
			Block *tempBlock = new BlockL{level->getLevelNumber()}; // TODO: level->getSpecificBlock(currCommand);
			if (!tryNewBlock(tempBlock)) {
				// Unable to place block. Maybe inform textDisplay to output that via observer/subject?
			} else {
				// TODO: remove previous block
				placeCurrentBlock();
			}
		} else if (currCommand == "hint") {
			// TODO: call hint method
			// TODO: On the very next command, no matter what the command is, the hint must disappear from the displays
			bestPlace();
		}
		// TODO: add other commands, if any left
	}
	if (!gameOver) {
		Pos change = {xChange, yChange};
		transformedRefPoint = transformedRefPoint + change;
		transformedOr = (transformedOr + rotateChange) % 4;
		vector<Pos> transformedPoints = currentBlock->getOrPtsOf(transformedRefPoint, transformedOr);

		if (isFittable(initialPoints, transformedPoints, false)) {
			updateGrid(initialPoints, '-'); // TODO: Sets old points on grid to empty space '-'
			currentBlock->setRefPoint(transformedRefPoint);
			currentBlock->setCurrentOr(transformedOr);
			placeCurrentBlock();
		}
		return;
	}
	cout << "Game over at the end of notify" << endl;
	
}

bool GameBoard::tryNewBlock(Block *blockToBePlaced) { // default blockToBePlaced: nullptr
	
	bool checkWithCurrentBlock = false;

	if (blockToBePlaced == nullptr) {
		// blockToBePlaced = level->getBlock();
		blockToBePlaced = new BlockI{level->getLevelNumber()};
	} else {
		checkWithCurrentBlock = true;
	}
	
	int fitOrientation = 0;
	while (fitOrientation <= 4) {
		if (fitOrientation == 4) {
			return false;
		}
		vector<Pos> currOrientationPoints = blockToBePlaced->getOrPtsOf(blockToBePlaced->getRefPoint(fitOrientation), fitOrientation);
		vector<Pos> currentBlockPts = {};
		if (checkWithCurrentBlock) {
			// NOTE: needed to make sure new "required" block ignores the current block in the grid.
			int currentBlockOr = currentBlock->getCurrentOr();
			Pos currentBlockRP = currentBlock->getRefPoint(currentBlockOr);
			currentBlockPts = currentBlock->getOrPtsOf(currentBlockRP, currentBlockOr);
		}
		if (isFittable(currentBlockPts, currOrientationPoints, false)) {
			// Setting the current block on the board with given orientation
			if (checkWithCurrentBlock) { delete currentBlock; } // Also delete from grid
			currentBlock = blockToBePlaced;
			currentBlock->setInitialOrientation(fitOrientation);
			placeCurrentBlock();
			break;
		}
		++fitOrientation;
	}
	return true;
}

void GameBoard::placeCurrentBlock() {
	int currO = currentBlock->getCurrentOr();
	Pos rp = currentBlock->getRefPoint(currO);
	vector<Pos> currOrientationPoints = currentBlock->getOrPtsOf(rp, currO);
	updateGrid(currOrientationPoints, currentBlock->getLetter());
}

void GameBoard::updateGrid(vector<Pos> points, char letter) {
	for (auto &k : points) {
		getCellAt(k).set(letter); // setting cell letter
	}
}

bool GameBoard::isFittable(const vector<Pos> &oldPoints, const vector<Pos> &newOrientation, const bool dropCheck) {

	for (auto &p : newOrientation) {
		int px = p.x;
		int py = p.y;
		int lowestY = dropCheck ? 3 : 0;
		if (px < 0 || px >= 11 || py < lowestY || py >= 18) {
			return false;
		}
		Cell currCell = getCellAt(p);
		char cLetter = currCell.getLetter();
		if (cLetter != '-') { // TODO: change to appropriate empty space
			int i = 0;
			for (i = 0; i < oldPoints.size(); i++) {
				if (oldPoints.at(i) == p) {
					i = 100;
				}
			}
			if (i < 100) {
				return false;
			}
		}
	}
	
	return true;
}

Cell &GameBoard::getCellAt(Pos p) {
	return grid.at(p.y).at(p.x);
}

void GameBoard::dropBlock() {
	bool dropSuccess = false;

	Pos refPoint = currentBlock->getRefPoint(currentBlock->getCurrentOr());
	int currO = currentBlock->getCurrentOr();

	vector<Pos> initialPoints = currentBlock->getOrPtsOf(refPoint, currO);
	vector<Pos> currPoints = initialPoints;

	while (isFittable(initialPoints, currPoints, false)) {
		refPoint.y += 1;
		currPoints = currentBlock->getOrPtsOf(refPoint, currO);
	}
	refPoint.y -= 1;
	currPoints = currentBlock->getOrPtsOf(refPoint, currO);

	if (isFittable(initialPoints, currPoints, true)) {
		dropSuccess = true;
		currentBlock->setRefPoint(refPoint);
		currentBlock->setDropped(true);
		placeCurrentBlock();
		updateGrid(initialPoints, '-');
		updateGrid(currPoints, currentBlock->getLetter());
		removeFullRows();
	} else {
	}
	// TODO: remove row(s) if full, etc
	// TODO: remove blocks that have been on the board for >= 10 turns
	// TODO: update score
}

void GameBoard::removeFullRows() {
	int removalCount = 0;
	int blocksRemoved = 0; // DEBUG
	for (int j = 17; j >= 0; j--) {
		bool full = true;
		for (int i = 0; i < 11; i++) {
			if (grid.at(j).at(i).getLetter() == '-') {
				full = false;
			}
		}
		if (full) {
			removalCount++;
			for (int p = blockList.size() - 1; p >= 0; p--) {
				blockList.at(p)->removeCellsAt(j);
				Block *b = blockList.at(p);
				int pSize = b->getOrPtsOf(b->getRefPoint(b->getCurrentOr()), b->getCurrentOr()).size();
				if (pSize == 0) {
					blocksRemoved++;
					lastTurnScore += ((blockList.at(p)->getLevelCreated() + 1) * (blockList.at(p)->getLevelCreated() + 1));
					delete blockList.at(p);
					blockList.erase(blockList.begin() + p);
				}
			}
			grid.erase(grid.begin() + j);
			vector<Cell> newRow = {};
			for (int k = 0; k < 11; k++) {
				newRow.emplace_back(Cell{k, j});
				newRow.back().attach(td);
			}
			grid.insert(grid.begin(), newRow);
			j++;
		}
	}
	if (removalCount != 0) {
		lastTurnScore += (removalCount + level->getLevelNumber()) * (removalCount + level->getLevelNumber());
	}
	scoreBoard.updateCurrentScore(lastTurnScore);
	lastTurnScore = 0;
	refreshBoard();
}


void GameBoard::refreshBoard() {
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 11; j++) {
			grid.at(i).at(j).setPos({j, i});
		}
	}
}


void GameBoard::levelChange(bool goUp) {
	// TODO: make level go up if goUp, else level go down
	// TODO: change level in scoreboard as well
	cout << "Gameboard says: Level change" << endl;
}

// Hint method ---------------------------------------

int GameBoard::totalEmptyRows() {
	bool isEmptyRow=true; // used
	int totalEmptyRows=0; // used
	int totalEmptyCellsInTopRow=0;
	int countFullRow=0; // used
	for(int row=0; row<18; ++row)  {
			for(int col=0; col<11; ++col) {
				if(grid[row][col].getLetter() != '-') {
					isEmptyRow = false;
					countFullRow += 1;
				}
			}
			if(isEmptyRow || (countFullRow==11)) {
				totalEmptyRows += 1;
			}
			if(countFullRow<11) {
				totalEmptyCellsInTopRow = 11 - countFullRow;
				break;
			}
			countFullRow = 0;
			isEmptyRow = true;
		}
		return totalEmptyRows+totalEmptyCellsInTopRow;
}

void GameBoard::bestPlace() {

	int currO = currentBlock->getCurrentOr();
	Pos rp = currentBlock->getRefPoint(currO);
	vector<Pos> currOrientationPoints = currentBlock->getOrPtsOf(rp, currO);


	Pos hintRefPt;
	int orientation;
	int maxEmptyRowsCells=0;
	int tempMaxEmptyRowsCells=0;
	char type = currentBlock->getLetter();

	for(int row=0; row<18; ++row) {
		for(int col=0; col<11; ++col) {
				for(int ort=0; ort<4; ++ort) {  // orientations
					if(isFittable(currOrientationPoints, currentBlock->getOrPtsOf({col,row}, ort), true)) {
					updateGrid(currentBlock->getOrPtsOf({col,row}, ort), type);
					tempMaxEmptyRowsCells = totalEmptyRows();
					if(tempMaxEmptyRowsCells >= maxEmptyRowsCells) {
						maxEmptyRowsCells = tempMaxEmptyRowsCells;
						hintRefPt = {col,row};
						orientation = ort;
						updateGrid(currentBlock->getOrPtsOf({col,row}, ort), '-');
						currOrientationPoints = currentBlock->getOrPtsOf({col,row}, ort);
						}
					}
				}
			}	
		}
	updateGrid(currentBlock->getOrPtsOf(hintRefPt, orientation), '?');
}



// Subject method ---------------------------------

// GameBoardData GameBoard::getData() {
// 	return {grid, gameOver, 0, scoreBoard.getHiScore(), scoreBoard.getCurrentScore()};
// }

// Big 5 + ctor --------------------------------------


GameBoard::GameBoard(TextDisplay *td)// , GraphicsDisplay *gd)
: grid{}, 
lastTurnScore{0},
 currentBlock{nullptr},
  blockList{}, 
  level{new Level1{}}, 
  scoreBoard{},
  gameOver{false},
  td{td} {
  	scoreBoard.attach(td);
  	scoreBoard.updateLevel(level->getLevelNumber());
	for (int i = 0; i < 18; i++) {
		grid.emplace_back();
		for (int j = 0; j < 11; j++) {
			Cell c{j, i};
			grid.back().emplace_back(c);
			grid.back().back().attach(td);
		}
	}
}

void GameBoard::init() {
	nextBlock = level->getBlock(); // Gets block from level
	tryNewBlock();
}



GameBoard::~GameBoard() {
	// TODO: should we delete the currentBlock ptr?
	for (auto it = blockList.begin(); it != blockList.end(); ++it) {
		delete (*it);
		(*it) = nullptr;
	}
	delete level;
	level = nullptr;
}


