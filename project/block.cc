#include "block.h"

using namespace std;

// void Block::translateX(bool toRight) {
// 	// gameBoard should be validating this increment
// 	refPoints.at(0).x += (toRight ? 1 : -1);
// 	lockOrientationsAbout(refPoints.at(0));
// }

// vector<Pos> Block::getTranslatedX(int orientationVal, bool toRight) const {
// 	vector<Pos> cpy = orientations.at(orientationVal);
// 	int xChange = 0;
// 	if (toRight) {
// 		xChange = 1;
// 	} else {
// 		xChange = -1;
// 	}
// 	for (auto &p : cpy) {
// 		p->x += xChange;
// 	}
// 	return cpy;
// }

// vector<Pos> Block::getTranslatedY(int orientationVal) const {
// 	vector<Pos> cpy = orientations.at(orientationVal);
// 	for (auto &p : cpy) {
// 		p->y += 1;
// 	}
// 	return cpy;
// }

// vector<Pos> Block::getRotated(bool clockwise) const {
// 	int direction = clockwise ? 1 : -1;
// 	vector<Pos> cpy = orientations.at((currOrientation + direction) % 4);
// 	return cpy;
// }


// // TODO: deletable
// vector<Pos> Block::getOrientationPoints(int i) { // NOTE: i is the orientation (0, 1, 2, 3)
// 	return orientations.at(i);
// }



// void Block::translateY() {
// 	// gameBoard should be validating this increment
// 	refPoints.at(0).y += 1;
// 	lockOrientationsAbout(refPoints.at(0));
// }

// void Block::checkOrientation(const Block &b) {
// 	// TODO: check if used
// 	// int count = 0;
// 	// for(int i=0; i<4; ++i) {
// 	// 	for(int j=0; j<4; ++j) {
// 	// 		if(orientations.at(i).at(j) != b.orientations.at(i).at(j)) {
// 	// 			break;
// 	// 		}
// 	// 		count += 1;
// 	// 	}
// 	// 	if(count==4) {
// 	// 		currOrientation = i;
// 	// 		break;
// 	// 	}
// 	// }
// }

vector<Pos> Block::getCurrOrientationPoints() { // USED
	return orientations.at(currOrientation);
}

void Block::setOrientation(int i) { // USED
	currOrientation = i;
}

void Block::setInitialOrientation(int initOrientation) { // USED
	refPoints.at(0) = refPoints.at(initOrientation);
	refPoints.erase(refPoints.begin() + 1);
	refPoints.erase(refPoints.begin() + 1);
	refPoints.erase(refPoints.begin() + 1);
}


void Block::rotate(bool clockwise) { // USED
	int direction = clockwise ? 1 : -1;
	currOrientation = (currOrientation + direction) % 4;
}

void Block::setRefPoint(Pos newRefPoint) { // USED
	refPoints.at(0) = newRefPoint;
	lockOrientationsAbout(refPoints.at(0));
}

vector<Pos> Block::getOrientationWith(Pos otherRefPoint, int otherOrientation) const { // USED
	return getOrientationsAt(otherRefPoint).at(otherOrientation);
}

void Block::lockOrientationsAbout(Pos refPoint) { // USED
	orientations = getOrientationsAt(refPoint);
}

Pos Block::getRefPoint() const {
	return refPoints.at(0);
}

int Block::getCurrentOrientation() {
	return currOrientation;
}

// Gets orientation orValue about position refPoint
vector<Pos> Block::getOrientationAtPoint(int orValue) {
	lockOrientationsAbout(refPoints.at(orValue));
	return orientations.at(orValue);
}

// Big 5 + ctor ----------------------------------

Block::Block() // USED
: refPoints{}, orientations{}, currOrientation{0} {
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