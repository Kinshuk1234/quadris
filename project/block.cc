#include "block.h"
#include <iostream>

using namespace std;

void Block::setRefPoint(Pos newRefPoint) { 
	orientations = getOrientationsAt(newRefPoint);
	refPoints.at(0) = newRefPoint;
	refPoints.at(1) = newRefPoint;
	refPoints.at(2) = newRefPoint;
	refPoints.at(3) = newRefPoint;
}

vector<Pos> Block::getOrPtsOf(Pos givenRefPoint, int givenOrientation) const {
	if (isDropped) {
		return orientations.at(givenOrientation);
	}
	return getOrientationsAt(givenRefPoint).at(givenOrientation);
}

int Block::getCurrentOr() const {
	return currOrientation;
}

void Block::setCurrentOr(int newO) {
	currOrientation = newO;
}

Pos Block::getRefPoint(int o) const {
	return refPoints.at(o);
}

void Block::setInitialOrientation(int initOrientation) { // USED
	currOrientation = initOrientation;
	int size = refPoints.size();
	Pos toBeSet = refPoints.at(initOrientation);
	for (int i = 0; i < size; i++) {
		refPoints.at(i)	= toBeSet;
	}
}

void Block::setDropped(bool dropped) {
	isDropped = dropped;
}

void Block::removeCellsAt(int row) {
	for (int k = orientations.at(currOrientation).size() - 1; k >= 0; k--) {
		// Pos refPoint = getRefPoint(currOrientation);
		if (orientations.at(currOrientation).at(k).y == row) {
			orientations.at(currOrientation).erase(orientations.at(currOrientation).begin() + k);
		}
	}
	for (int k = orientations.at(currOrientation).size() - 1; k >= 0; k--) {
		if (orientations.at(currOrientation).at(k).y < row) {
			orientations.at(currOrientation).at(k).y += 1;
		}
	}
	
}

int Block::getLevelCreated() const {
	return levelCreated;
}

bool Block::getIsHeavy() const {
	return isHeavy;
}

void Block::turnCountAddOne() {
	turnCount++;
}

int Block::getTurnCount() {
	return turnCount;
}


// Big 5 + ctor ----------------------------------

Block::Block(int levelCreated, bool isHeavy) // USED
: orientations{}, refPoints{}, currOrientation{0}, isDropped{false}, levelCreated{levelCreated}, isHeavy{isHeavy} {
	refPoints.emplace_back();
	refPoints.emplace_back();
	refPoints.emplace_back();
	refPoints.emplace_back();
	orientations.emplace_back();
	orientations.emplace_back();
	orientations.emplace_back();
	orientations.emplace_back();
}

Block::~Block() {}


