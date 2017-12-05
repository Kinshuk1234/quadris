#include "blocki.h"
#include <iostream>

using namespace std;

class GameBoard;


BlockI::BlockI(int levelCreated, bool isHeavy)
: Block{levelCreated, isHeavy}, myType{'I'} {
	refPoints.at(0) = {0, 3};
	refPoints.at(1) = {0, 6};
	refPoints.at(2) = {0, 3}; 
	refPoints.at(3) = {0, 6};
}

vector<vector<Pos>> BlockI::getOrientationsAt(Pos refPoint) const {
	int refX = refPoint.x;
	int refY = refPoint.y;
	vector<vector<Pos>> oCpy;
	oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back();
	oCpy.at(0) = {{refX, refY}, {refX + 1, refY}, {refX + 2, refY}, {refX + 3, refY}};
	oCpy.at(1) = {{refX, refY}, {refX, refY - 1}, {refX, refY - 2}, {refX, refY - 3}};
	oCpy.at(2) = {{refX, refY}, {refX + 1, refY}, {refX + 2, refY}, {refX + 3, refY}};
	oCpy.at(3) = {{refX, refY}, {refX, refY - 1}, {refX, refY - 2}, {refX, refY - 3}};
	return oCpy;
}


char BlockI::getLetter() {
	return myType;
}


