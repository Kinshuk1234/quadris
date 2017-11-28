#include "BlockL.h"
#include <iostream>

using namespace std;

class GameBoard;

// Here, inside the constructor of BlockI, I have stored the coordinates
// in the order they appear, that is, either starting with the top left coordinate or 
// bottom left coordinate. I haven't stored the coordinate of lower
// left corner first   

BlockL::BlockL() {
	vector<Pos> p1 = {{0,1},{1,1},{2,1},{2,0}};
	orientations.emplace_back(p1);
	vector<Pos> p2 = {{0,0},{0,1},{0,2},{1,2}};
	orientations.emplace_back(p2);
	vector<Pos> p3 = {{0,1},{0,0},{1,0},{2,0}};
	orientations.emplace_back(p3);
	vector<Pos> p4 = {{0,0},{1,0},{1,1},{1,2}};
	orientations.emplace_back(p4);
}



























