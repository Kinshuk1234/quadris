#include "blocki.h"
#include <iostream>

using namespace std;

class GameBoard;

// Here, inside the constructor of BlockI, I have stored the coordinates
// in the order they appear, that is, either starting with the top left coordinate or 
// bottom left coordinate. I haven't stored the coordinate of lower
// left corner first   

BlockI::BlockI() {
	vector<Pos> p1 = {{0,0},{1,0},{2,0},{3,0}};
	orientations.emplace_back(p1);
	vector<Pos> p2 = {{0,0},{0,1},{0,2},{0,3}};
	orientations.emplace_back(p2);
	vector<Pos> p3 = {{0,0},{1,0},{2,0},{3,0}};
	orientations.emplace_back(p3);
	vector<Pos> p4 = {{0,0},{0,1},{0,2},{0,3}};
	orientations.emplace_back(p4);
}

std::vector<std::vector<Pos>> BlockI::getOrientationsAt(Pos refPoint) const {
	return {}; // TODO
}

char BlockI::getLetter() {
	return '-'; // TODO
}


