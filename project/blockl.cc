#include "blockl.h"
#include <iostream>

using namespace std;

class GameBoard;

BlockL::BlockL(int levelCreated, bool isHeavy)
: Block{levelCreated, isHeavy}, myType{'L'} {
	refPoints.at(0) = {0, 5};
	refPoints.at(1) = {0, 4};
	refPoints.at(2) = {0, 5}; 
	refPoints.at(3) = {0, 4};
}

vector<vector<Pos>> BlockL::getOrientationsAt(Pos refPoint) const {
	int refX = refPoint.x;
	int refY = refPoint.y;
	vector<vector<Pos>> oCpy;
	oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back();
	oCpy.at(0) = {{refX, refY}, {refX, refY - 1}, {refX, refY - 2}, {refX + 1, refY}};
	oCpy.at(1) = {{refX, refY}, {refX, refY - 1}, {refX + 1, refY - 1}, {refX + 2, refY - 1}};
	oCpy.at(2) = {{refX, refY - 2}, {refX + 1, refY - 2}, {refX + 1, refY - 1}, {refX + 1, refY}};
	oCpy.at(3) = {{refX, refY}, {refX + 1, refY}, {refX + 2, refY}, {refX + 2, refY - 1}};
	return oCpy;
}


char BlockL::getLetter() { // USED
	return myType;
}







