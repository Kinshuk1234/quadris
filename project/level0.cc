#include "level0.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
using namespace std;

Level0::Level0(string filename)
: v{} {
	char blockType;
	ifstream f{filename};

	while(f >> blockType) {
		v.emplace_back(blockType);
	}

}

Block* Level0::getBlock() {
	char firstLetter = v.at(0);
	if (firstLetter == 'I') {
		v.erase(v.begin());
		return new BlockI{getLevelNumber()};
	}
	else if (firstLetter == 'J') {
		v.erase(v.begin());
		return new BlockJ{getLevelNumber()};
	}
	else if (firstLetter == 'L') {
		v.erase(v.begin());
		return new BlockL{getLevelNumber()};
	}
	else if (firstLetter == 'O') {
		v.erase(v.begin());
		return new BlockO{getLevelNumber()};
	}
	else if (firstLetter == 'S') {
		v.erase(v.begin());
		return new BlockS{getLevelNumber()};
	}
	else if (firstLetter == 'Z') {
		v.erase(v.begin());
		return new BlockZ{getLevelNumber()};
	}
	else {
		v.erase(v.begin());
		return new BlockT{getLevelNumber()};
	}
}

Level0::~Level0() {}

int Level0::getLevelNumber() const {
	return 0;
}
