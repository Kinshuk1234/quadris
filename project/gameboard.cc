#include <memory>
#include "gameboard.h"
#include "scoreboard.h"
#include "textdisplay.h"
// #include "graphicsdisplay.h"
#include <iostream>
#include "quadris.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "blockl.h"
#include "blocki.h"
#include "blockj.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
#include "blockdot.h"

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
		if(lastWasHint) {
			updateGrid(hintPoints, '-');
			lastWasHint = false;
		}
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
				updateGrid(initialPoints, '-');
				currentBlock->setRefPoint(transformedRefPoint);
				currentBlock->setCurrentOr(transformedOr);
				blockList.emplace_back(currentBlock);
				placeCurrentBlock();
				dropBlock(currentBlock);
				// if (enhancedVersion) {
				updateBlockTurnCounts();
				removeOldBlocks();
				// }
				if (level->getLevelNumber() == 4) {
					Block *dot = new BlockDot{4, false};
					vector<Pos> pts = dot->getOrPtsOf(dot->getRefPoint(dot->getCurrentOr()), dot->getCurrentOr());
					cout << pts.at(0) << endl;
					if (isFittable({}, pts, false) and (blockList.size() % 5 == 0)) {
						dropBlock(dot);
					}
				}
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
			levelChange(true);
		} else if (currCommand == "leveldown") {
			levelChange(false);
		} else if (currCommand == "I"
				 or currCommand == "J"
				 or currCommand == "L"
				 or currCommand == "O"
				 or currCommand == "S"
				 or currCommand == "T"
				 or currCommand == "Z") {
			Block *tempBlock =  level->getBlock(); //level->getSpecificBlock(currCommand);
			if (!tryNewBlock(tempBlock)) {
				// Unable to place block. Maybe inform textDisplay to output that via observer/subject?
			} else {
				// TODO: remove previous block
				placeCurrentBlock();
			}
		} else if (currCommand == "hint") {
			bestPlace();
			lastWasHint = true;
		} else if (currCommand == "restart") {
			restartGame();
			xChange = 0;
			yChange = 0;
			rotateChange = 0;
			initialPoints = currentBlock->getOrPtsOf(currentBlock->getRefPoint(currentBlock->getCurrentOr()), currentBlock->getCurrentOr());
			transformedRefPoint = currentBlock->getRefPoint(currentBlock->getCurrentOr());
		} else if(currCommand == "norandom") {
			if(level->getLevelNumber()==3) {
				delete level;
				level = new Level3{seed, false};
			} else if (level->getLevelNumber() == 4) {
				delete level;
				level = new Level4{seed, false};
			}
				delete nextBlock;
				nextBlock = level->getBlock();
				scoreBoard.updateNextBlock(nextBlock->getLetter());
		} else if(currCommand == "random") {
			if(level->getLevelNumber() == 3) {
				delete level;
				level = new Level3{seed, true};
			} else if (level->getLevelNumber() == 4) {
				delete level;
				level = new Level4{seed, true};
			}
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

void GameBoard::updateBlockTurnCounts() {
	for (auto &p : blockList) {
		p->turnCountAddOne();
	}
}

void GameBoard::removeOldBlocks() {
	for (int b = blockList.size() - 1; b >= 0; b--) {
		Block *p = blockList.at(b);
		if (p->getTurnCount() >= 10) {
			updateGrid(p->getOrPtsOf(p->getRefPoint(p->getCurrentOr()), p->getCurrentOr()), '-');
			blockList.erase(blockList.begin() + b);
		}
	}
}

void GameBoard::restartGame() {
	delete level;
	level = new Level0{}; // new Level0{};
	scoreBoard.setCurrentScore(0);
	scoreBoard.updateLevel(level->getLevelNumber());
	for (auto &p : blockList) {
		delete p;
	}
	blockList = {};
	for (auto &q : grid) {
		for (auto &r : q) {
			if (r.getLetter() != '-') {
				r.set('-');
			}
		}
	}
	delete nextBlock;
	delete currentBlock;
	nextBlock = level->getBlock(); // Gets block from 
	tryNewBlock();

}

bool GameBoard::tryNewBlock(Block *blockToBePlaced) { // default blockToBePlaced: nullptr
	
	bool checkWithCurrentBlock = false;

	if (blockToBePlaced == nullptr) {
		blockToBePlaced = nextBlock;
		nextBlock = level->getBlock();
		scoreBoard.updateNextBlock(nextBlock->getLetter());
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

void GameBoard::dropBlock(Block *b) {
	bool dropSuccess = false;

	Pos refPoint = b->getRefPoint(b->getCurrentOr());
	int currO = b->getCurrentOr();

	vector<Pos> initialPoints = b->getOrPtsOf(refPoint, currO);
	vector<Pos> currPoints = initialPoints;

	while (isFittable(initialPoints, currPoints, false)) {
		refPoint.y += 1;
		currPoints = b->getOrPtsOf(refPoint, currO);
	}
	refPoint.y -= 1;
	currPoints = b->getOrPtsOf(refPoint, currO);

	if (isFittable(initialPoints, currPoints, true)) {
		dropSuccess = true;
		b->setRefPoint(refPoint);
		b->setDropped(true);
		placeCurrentBlock();
		updateGrid(initialPoints, '-');
		updateGrid(currPoints, b->getLetter());
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
				// newRow.back().attach(gd);
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
	int currentLevelNumber = level->getLevelNumber();
	delete level;
	if (goUp) {
		currentLevelNumber += 1;
	} else {
		currentLevelNumber -= 1;
	}
	if (currentLevelNumber >= 4) {
		level = new Level4{}; // TODO: new Level4{}
	} else if (currentLevelNumber == 3) {
		level = new Level3{};
	} else if (currentLevelNumber == 2) {
		level = new Level2{};
	} else if (currentLevelNumber == 1) {
		level = new Level1{};
	} else {
		level = new Level0{};
	}
	scoreBoard.updateLevel(currentLevelNumber);
}

// Hint method ---------------------------------------

bool GameBoard::checkCoor(int col, int row, vector<Pos> currentBlockPoints) {
	for(int i=0; i<4; ++i) {
		if((col==currentBlockPoints[i].x)&&(row==currentBlockPoints[i].y)) {
			return true;
	    }
	}
	return false;
}

int GameBoard::totalEmptyRows(vector<Pos> currentBlockPoints) {
	int emptyCellCount = 0;
	int totalEmptyRows=0; // used
	int totalEmptyCellsInTopRow=0; // used
	int countFullRow=0; // used
	for(int row=3; row<18; ++row)  {
			for(int col=0; col<11; ++col) {

				if(checkCoor(col,row,currentBlockPoints)) {
					emptyCellCount += 1;
					continue;
				}

				if(grid[row][col].getLetter() != '-') {
					countFullRow += 1;
				} else {
					emptyCellCount += 1;
				}

			}

			if(emptyCellCount==11 || (countFullRow==11)) {
				totalEmptyRows += 1;
			}

			if(countFullRow<11) {
				totalEmptyCellsInTopRow = 11 - countFullRow;
				break;
			}

			countFullRow = 0;
			emptyCellCount = 0;
		}
		return totalEmptyRows+totalEmptyCellsInTopRow;
}

void GameBoard::bestPlace() {

	int currO = currentBlock->getCurrentOr();
	Pos rp = currentBlock->getRefPoint(currO);
	vector<Pos> currOrientationPoints = currentBlock->getOrPtsOf(rp, currO);
	vector<Pos> initialPoints = currOrientationPoints;

	Pos hintRefPt;
	int orientation;
	int maxEmptyRowsCells=0;
	int tempMaxEmptyRowsCells=0;
	char type = currentBlock->getLetter();

	for(int row=3; row<18; ++row) {
		for(int col=0; col<11; ++col) {
			for(int ort=0; ort<4; ++ort) {
					if(isFittable(currOrientationPoints, currentBlock->getOrPtsOf({col,row}, ort), true)) {
					updateGrid(currentBlock->getOrPtsOf({col,row}, ort), type);
					tempMaxEmptyRowsCells = totalEmptyRows(initialPoints);
					updateGrid(currentBlock->getOrPtsOf({col,row}, ort), '-');
					if(tempMaxEmptyRowsCells >= maxEmptyRowsCells) {
						maxEmptyRowsCells = tempMaxEmptyRowsCells;
						hintRefPt = {col,row};
						orientation = ort;
						//currOrientationPoints = currentBlock->getOrPtsOf({col,row}, ort);
					}
				}
			}
		}	
	}
	updateGrid(currentBlock->getOrPtsOf(hintRefPt, orientation), '?');
	hintPoints = currentBlock->getOrPtsOf(hintRefPt, orientation);
}


// Subject method ---------------------------------

// GameBoardData GameBoard::getData() {
// 	return {grid, gameOver, 0, scoreBoard.getHiScore(), scoreBoard.getCurrentScore()};
// }

// Big 5 + ctor --------------------------------------

// Add graphicsDisplay pointer
GameBoard::GameBoard(TextDisplay *td, int startLevel, int seed, string filename) //, GraphicsDisplay *gd)
// TODO:: Assign correct level by using the parameter "level"
: grid{}, 
lastTurnScore{0}, 
 currentBlock{nullptr},
  blockList{}, 
  scoreBoard{},
  td{td}, // gd{gd} 
  gameOver{false},
  seed{seed} {  

	if(startLevel==0) {
		level = new Level0{filename};
	} else if(startLevel==1) {
		level = new Level1{seed};
	} else if(startLevel==2) {
		level = new Level2{seed};
	} else if(startLevel==3) {
		level = new Level3{seed};
	} else if(startLevel==4) {
		level = new Level4{seed};
	}

  	scoreBoard.attach(td);
  	// scoreBoard.attach(gd);
  	scoreBoard.updateLevel(level->getLevelNumber());
	for (int i = 0; i < 18; i++) {
		grid.emplace_back();
		for (int j = 0; j < 11; j++) {
			Cell c{j, i};
			grid.back().emplace_back(c);
			grid.back().back().attach(td);
			// grid.back().back().attach(gd);
		}
	}
}

void GameBoard::init() {
	nextBlock = level->getBlock(); // Gets block from 
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


