#include "level0.h"

using namespace std;

Level0::Level0(string filename) {
	char blockType;
	ifstream f{filename};
	while(f >> blockType) {
		v.emplace_back(blockType);	
	}
}

Block* Level0::getBlock() {
	if (v.begin() == "I") {
		v.erase(v.begin());
		return new BlockI;
	}
	else if (v.begin() == "J") {
		v.erase(v.begin());
		return new BlockJ;
	}
	else if (v.begin() == "L") {
		v.erase(v.begin());
		return new BlockL;
	}
	else if (v.begin() == "O") {
		v.erase(v.begin());
		return new BlockO;
	}
	else if (v.begin() == "S") {
		v.erase(v.begin());
		return new BlockS;
	}
	else if (v.begin() == "Z") {
		v.erase(v.begin());
		return new BlockZ;
	}
	else {
		v.erase(v.begin());
		return new BlockT;
	}
}

Level0::~Level0() {}
