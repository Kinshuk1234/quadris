#include "blocks.h"
#include <iostream>

using namespace std;

class GameBoard;

BlockS::BlockS()
: myType{'S'} {
	refPoints.at(0) = {0, 4};
	refPoints.at(1) = {0, 5};
	refPoints.at(2) = {0, 4}; 
	refPoints.at(3) = {0, 5};
}

vector<vector<Pos>> BlockS::getOrientationsAt(Pos refPoint) const {
	int refX = refPoint.x;
	int refY = refPoint.y;
	vector<vector<Pos>> oCpy;
	oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back();
	oCpy.at(0) = {{refX, refY}, {refX + 1, refY}, {refX + 1, refY - 1}, {refX + 2, refY - 1}};
	oCpy.at(1) = {{refX, refY - 2}, {refX, refY - 1}, {refX + 1, refY - 1}, {refX + 1, refY}};
	oCpy.at(2) = {{refX, refY}, {refX + 1, refY}, {refX + 1, refY - 1}, {refX + 2, refY - 1}};
	oCpy.at(3) = {{refX, refY - 2}, {refX, refY - 1}, {refX + 1, refY - 1}, {refX + 1, refY}};
	return oCpy;
}


char BlockS::getLetter() { // USED
	return myType;
}

// THERE ARE ONLY 2 POSSIBLE ROTATIONS
