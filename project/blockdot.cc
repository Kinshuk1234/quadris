#include "blockdot.h"

using namespace std;

class GameBoard;


BlockDot::BlockDot(int levelCreated, bool isHeavy)
: Block{levelCreated, isHeavy}, myType{'*'} {
	refPoints.at(0) = {5, 3};
	refPoints.at(1) = {5, 3};
	refPoints.at(2) = {5, 3}; 
	refPoints.at(3) = {5, 3};
}

vector<vector<Pos>> BlockDot::getOrientationsAt(Pos refPoint) const {
	int refX = refPoint.x;
	int refY = refPoint.y;
	vector<vector<Pos>> oCpy;
	oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back(); oCpy.emplace_back();
	oCpy.at(0) = {{refX, refY}};
	oCpy.at(1) = {{refX, refY}};
	oCpy.at(2) = {{refX, refY}};
	oCpy.at(3) = {{refX, refY}};
	return oCpy;
}


char BlockDot::getLetter() { // USED
	return myType;
}
