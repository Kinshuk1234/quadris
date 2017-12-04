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
: v{}, blockIndex{0} {
	char blockType;
	ifstream f{filename};

	while(f >> blockType) {
		v.emplace_back(blockType);
	}

}

Block* Level0::getBlock() {
	char firstLetter = v.at(blockIndex);
	blockIndex = (blockIndex+1) % v.size();
	if (firstLetter == 'I') {
		return new BlockI{getLevelNumber()};
	}
	else if (firstLetter == 'J') {
		return new BlockJ{getLevelNumber()};
	}
	else if (firstLetter == 'L') {
		return new BlockL{getLevelNumber()};
	}
	else if (firstLetter == 'O') {
		return new BlockO{getLevelNumber()};
	}
	else if (firstLetter == 'S') {
		return new BlockS{getLevelNumber()};
	}
	else if (firstLetter == 'Z') {
		return new BlockZ{getLevelNumber()};
	}
	else {
		return new BlockT{getLevelNumber()};
	}
}

Level0::~Level0() {}

int Level0::getLevelNumber() const {
	return 0;
}
