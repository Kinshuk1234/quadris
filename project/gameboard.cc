#include <memory>
#include "gameboard.h"
#include "scoreboard.h"
#include "textdisplay.h"
#include <iostream>
#include "level0.h"

using namespace std;


void GameBoard::notify(Subject<vector<string>> &notifier) {
	vector<string> arr = notifier.getData();
	// TODO: check if after run of commands, the block is in a valid place.
	// i.e. inside the board AND not overlapping another block

	for (auto it = arr.begin(); it != arr.end(); ++it) {
		string currCommand = *it;
		if (currCommand == "left") {
			moveX(true);
		} else if (currCommand == "right") {
			moveX(false);
		} else if (currCommand == "down") {
			moveY();
		} else if (currCommand == "clockwise") {
			rotate(true);
		} else if (currCommand == "counterclockwise") {
			rotate(false);
		} else if (currCommand == "drop") {
			dropBlock();
		} else if (currCommand == "levelup") {
			// TODO: level up.
		}
		// TODO: add other commands, if any left
	}
}

void GameBoard::setCurrentBlock(Block *b) {
	currentBlock = b;
	blockList.emplace_back(currentBlock);
	// TODO: set the current block to the given block.
}

void GameBoard::dropBlock() {
	// TODO: drop block
	// TODO: remove row(s) if full, etc
	// TODO: remove blocks that have been on the board for >= 10 turns
	// TODO: update score
	cout << "Gameboard says: Drop block" << endl;
}

void GameBoard::moveX(bool goLeft) {
	// TODO: see if block can move that much in that direction
	// TODO: if so, move it
	cout << "Gameboard says: move in X dir" << endl;
}

void GameBoard::moveY() { // TODO: amount can only be positive!
	// TODO: see if block can move that much in that direction
	// TODO: if so, move it
	cout << "Gameboard says: move in Y dir" << endl;
}

void GameBoard::rotate(bool isClockwise) {
	cout << "Gameboard says: rotate block" << endl;
	if (isClockwise) {
		// TODO: rotate currentBlock clockwise
	} else {
		// TODO: rotate currentBlock counter-clockwise
	}
}

void GameBoard::levelChange(bool goUp) {
	// TODO: make level go up if goUp, else level go down
	cout << "Gameboard says: Level change" << endl;
}

// Big 5 + ctor --------------------------------------


GameBoard::GameBoard(TextDisplay *td)
: grid{}, lastTurnScore{0}, currentBlock{nullptr}, blockList{}, level{new Level0{}}, scoreBoard{} {
	for (int i = 0; i < 18; i++) {
		grid.emplace_back();
		for (int j = 0; j < 11; j++) {
			Cell c{i, j};
			grid.back().emplace_back(c);
			grid.back().back().attach(td);
		}
	}
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


