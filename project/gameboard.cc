#include <memory>
#include "gameboard.h"
#include "scoreboard.h"
#include "textdisplay.h"
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
	// TODO: check if after run of commands, the block is in a valid place.
	// i.e. inside the board AND not overlapping another block

	int xChange = 0;
	int yChange = 0;
	int rotateChange = 0;
	int transformedOrientation = currentBlock->getCurrentOr();
	Pos transformedRefPoint = currentBlock->getRefPoint(transformedOrientation);
	vector<Pos> initialPoints = currentBlock->getOrPtsOf(transformedRefPoint, transformedOrientation);

	for (auto it = arr.begin(); it != arr.end(); ++it) {
		string currCommand = *it;
		if (currCommand == "left") {
			xChange -= 1;
			cout << "Going Left" << endl;
			// TODO: if block isHeavy, move down one
		} else if (currCommand == "right") {
			xChange += 1;
			cout << "Going Right" << endl;
			// TODO: if block isHeavy, move down one, if valid
		} else if (currCommand == "down") {
			yChange += 1;
		} else if (currCommand == "clockwise") {
			rotateChange += 1;
			// TODO: if block isHeavy, move down one
		} else if (currCommand == "counterclockwise") {
			rotateChange = rotateChange + 4 - 1;
			// TODO: if block isHeavy, move down one
		} else if (currCommand == "drop") {
			// TODO: check the transformations
			transformedRefPoint.x += xChange;
			transformedRefPoint.y += yChange;
			transformedOrientation = (transformedOrientation + rotateChange) % 4; 
			vector<Pos> transformedPoints = currentBlock->getOrPtsOf(transformedRefPoint, transformedOrientation);
			if (isFittable(initialPoints, transformedPoints, false)) {
				dropBlock();
				transformedRefPoint.x = currentBlock->getRefPoint(currentBlock->getCurrentOrientation()).x;
				transformedRefPoint.y = currentBlock->getRefPoint(currentBlock->getCurrentOrientation()).y;
				transformedOrientation = currentBlock->getCurrentOrientation();
				xChange = 0;
				yChange = 0;
				rotateChange = 0;
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
			Block *tempBlock = new BlockL;; // TODO: level->getSpecificBlock(currCommand);
			if (!tryNewBlock(tempBlock)) {
				// Unable to place block. Maybe inform textDisplay to output that via observer/subject?
			} else {
				// TODO: remove previous block
				setCurrentBlock2();
			}
		} else if (currCommand == "hint") {
			// TODO: call hint method
			// On the very next command, no matter what the command is, the hint must disappear from the displays
			bestPlace();
		}
		// TODO: add other commands, if any left
	}
	transformedRefPoint.x += xChange;
	transformedRefPoint.y += yChange;
	transformedOrientation = (transformedOrientation + rotateChange) % 4;
	vector<Pos> transformedPoints = currentBlock->getOrPtsOf(transformedRefPoint, transformedOrientation);

	#ifdef DEBUG	
	cout << "Initial Points: " << endl;
	cout << initialPoints.at(0).x << initialPoints.at(0).y << endl;
	cout << initialPoints.at(1).x << initialPoints.at(1).y << endl;
	cout << initialPoints.at(2).x << initialPoints.at(2).y << endl;
	cout << initialPoints.at(3).x << initialPoints.at(3).y << endl;
	cout << "Transformed Points: " << endl;
	cout << transformedPoints.at(0).x << transformedPoints.at(0).y << endl;
	cout << transformedPoints.at(1).x << transformedPoints.at(1).y << endl;
	cout << transformedPoints.at(2).x << transformedPoints.at(2).y << endl;
	cout << transformedPoints.at(3).x << transformedPoints.at(3).y << endl;
	#endif

	if (isFittable(initialPoints, transformedPoints, false)) {
		updateGrid(initialPoints, '-'); // TODO: Sets old points on grid to empty space '-'
		currentBlock->setRefPoint(transformedRefPoint);
		currentBlock->setOrientation(transformedOrientation);
		setCurrentBlock2();
	}
}

bool GameBoard::tryNewBlock(Block *blockToBePlaced) { // default blockToBePlaced: nullptr
	
	if (blockToBePlaced == nullptr) {
		// blockToBePlaced = new BlockO();
		blockToBePlaced = level->getBlock();
	}
	
	int fitOrientation = 0;
	while (fitOrientation <= 4) {
		if (fitOrientation == 4) {
			return false;
		}
		vector<Pos> currOrientationPoints = blockToBePlaced->getOrPtsOf(blockToBePlaced->getRefPoint(fitOrientation), fitOrientation);
		if (isFittable({}, currOrientationPoints, false)) {
			// Setting the current block on the board with given orientation
			currentBlock = blockToBePlaced;
			currentBlock->setInitialOrientation(fitOrientation);
			setCurrentBlock2();
			break;
		}
		++fitOrientation;
	}
	return true;

	// TODO: set the current block to the given block.
}

void GameBoard::setCurrentBlock2() {
	int currO = currentBlock->getCurrentOr();
	Pos rp = currentBlock->getRefPoint(currO);
	vector<Pos> currOrientationPoints = currentBlock->getOrPtsOf(rp, currO);
	updateGrid(currOrientationPoints, currentBlock->getLetter());
	blockList.emplace_back(currentBlock);
}

void GameBoard::updateGrid(vector<Pos> points, char letter) {
	for (auto &k : points) {
		getCellAt(k.x, k.y).set(letter); // setting cell letter
	}
}

bool GameBoard::isFittable(const vector<Pos> &oldPoints, const vector<Pos> &newOrientation, bool dropCheck) {
	cout << newOrientation.at(0).x << newOrientation.at(0).y << endl;
	cout << newOrientation.at(1).x << newOrientation.at(1).y << endl;
	cout << newOrientation.at(2).x << newOrientation.at(2).y << endl;
	cout << newOrientation.at(3).x << newOrientation.at(3).y << endl;

	// START HERE: Block doesn't move because it recognizes it's own character as overlapping
	for (auto &p : newOrientation) {
		int px = p.x;
		int py = p.y;
		int i = 0;
		for (i = 0; i < oldPoints.size(); i++) {
			if (oldPoints.at(i) == p) {
				i = 100;
			}
		}
		if (i >= 100) {
		} else {
			int lowestY = dropCheck ? 3 : 0;
			if (px < 0 || px >= 11 || py < lowestY || py >= 18) {
				return false;
			}
			Cell currCell = getCellAt(px, py);
			char cLetter = currCell.getData().blockType;
			if (cLetter != '-') { // TODO: change to appropriate empty space
				return false;
			}
		}
		
	}
	return true;
}

Cell &GameBoard::getCellAt(int x, int y) {
	return grid.at(y).at(x);
}

void GameBoard::dropBlock() {
	bool dropSuccess = false;
	
	// TODO: only drop if all cells of the block are below the 3rd row (>= 4th row), can't use isFittable
	// TODO: drop block
	// TODO: remove row(s) if full, etc
	// TODO: remove blocks that have been on the board for >= 10 turns
	// TODO: update score

	// IF: drop successful: Here, it's starting the next turn by trying to place a block
	currentBlock = nullptr;

	if (tryNewBlock()) { // TODO: instead of doing this, can you notify Quadris that turn is over?
		setCurrentBlock2();
	} else {
		// TODO: Game Over sequence, unable to place next block.
	}
	// ELSE: drop not successful
	cout << "Gameboard says: Drop block" << endl;
	
}

void GameBoard::levelChange(bool goUp) {
	// TODO: make level go up if goUp, else level go down
	cout << "Gameboard says: Level change" << endl;
}

// Hint method ---------------------------------------

int GameBoard::totalEmptyRows() {
	bool isEmptyRow=true; // used
	int totalEmptyRows=0; // used
	int totalEmptyCellsInTopRow=0;
	int countFullRow=0; // used
	for(int i=0; i<18; ++i)  {
			for(int j=0; j<11; ++j) {
				if(grid[i][j].getData().blockType != '-') {
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
		}
		return totalEmptyRows+totalEmptyCellsInTopRow;
}

void GameBoard::bestPlace() {

	Block *temp = currentBlock;

	int currO = currentBlock->getCurrentOr();
	Pos rp = currentBlock->getRefPoint(currO);
	vector<Pos> currOrientationPoints = currentBlock->getOrPtsOf(rp, currO);


	Pos hintRefPt;
	int orientation;
	int maxEmptyRowsCells=0;
	int tempMaxEmptyRowsCells=0;
	char type = currentBlock->getLetter();
	//for(int i=0; i<4; ++i) {  // orientations
		for(int j=0; j<11; ++j) {
			for(int k=0; k<18; ++k) {
				for(int i=0; i<4; ++i) {  // orientations
				if(isFittable(currOrientationPoints, currentBlock->getOrPtsOf({j,k}, i), true)) {
					updateGrid(currentBlock->getOrPtsOf({j,k}, i), type);
					tempMaxEmptyRowsCells = totalEmptyRows();
					if(tempMaxEmptyRowsCells >= maxEmptyRowsCells) {
						maxEmptyRowsCells = tempMaxEmptyRowsCells;
						hintRefPt = {j,k};
						orientation = i;
						updateGrid(currentBlock->getOrPtsOf({j,k}, i), '-');
						currOrientationPoints = currentBlock->getOrPtsOf({j,k}, i);
					}
				}
			}
			}	
		}
	//}
	updateGrid(currentBlock->getOrPtsOf(hintRefPt, orientation), '?');
	currentBlock = temp;
}

// Big 5 + ctor --------------------------------------


GameBoard::GameBoard(TextDisplay *td)
: grid{}, lastTurnScore{0}, currentBlock{nullptr}, blockList{}, level{new Level1{}}, scoreBoard{} {
	for (int i = 0; i < 18; i++) {
		grid.emplace_back();
		for (int j = 0; j < 11; j++) {
			Cell c{i, j};
			grid.back().emplace_back(c);
			grid.back().back().attach(td);
		}
	}
}

void GameBoard::init() {
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


