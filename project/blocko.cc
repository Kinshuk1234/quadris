#include "blocko.h"
#include <iostream>

using namespace std;

class GameBoard;

BlockO::BlockO(int levelCreated, bool isHeavy)
: Block{levelCreated, isHeavy}, myType{'O'} {
	refPoints.at(0) = {0, 4};
	refPoints.at(1) = {0, 4};
	refPoints.at(2) = {0, 4}; 
	refPoints.at(3) = {0, 4};
}

vector<vector<Pos>> BlockO::getOrientationsAt(Pos refPoint) const {
	int refX = refPoint.x;
	int refY = refPoint.y;
	vector<vector<Pos>> oCpy;
	oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back();
	oCpy.at(0) = {{refX, refY}, {refX + 1, refY}, {refX + 1, refY - 1}, {refX, refY - 1}};
	oCpy.at(1) = {{refX, refY}, {refX + 1, refY}, {refX + 1, refY - 1}, {refX, refY - 1}};
	oCpy.at(2) = {{refX, refY}, {refX + 1, refY}, {refX + 1, refY - 1}, {refX, refY - 1}};
	oCpy.at(3) = {{refX, refY}, {refX + 1, refY}, {refX + 1, refY - 1}, {refX, refY - 1}};
	return oCpy;
}


char BlockO::getLetter() { // USED
	return myType;
}

// THERE IS ONLY ONE POSSIBLE ROTATION FOR O-BLOCK
