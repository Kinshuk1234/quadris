#include "blockt.h"
#include <iostream>

using namespace std;

class GameBoard;

// Here, inside the constructor of BlockT, I have stored the coordinates
// in the order they appear, that is, either starting with the top left coordinate or 
// bottom left coordinate. I haven't stored the coordinate of lower
// left corner first   

BlockT::BlockT() {
	vector<Pos> p1 = {{0,0},{1,0},{2,0},{1,1}};
	orientations.emplace_back(p1);
	vector<Pos> p2 = {{0,1},{1,0},{1,1},{1,2}};
	orientations.emplace_back(p2);
	vector<Pos> p3 = {{0,1},{1,1},{2,1},{1,0}};
	orientations.emplace_back(p3);
	vector<Pos> p4 = {{0,0},{0,1},{0,2},{1,1}};
	orientations.emplace_back(p4);
}

std::vector<std::vector<Pos>> BlockT::getOrientationsAt(Pos refPoint) const {
	return {}; // TODO
}

char BlockT::getLetter() {
	return '-'; // TODO
}

