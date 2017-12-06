#include "level.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"

using namespace std;

Level::~Level() {}

Level::Level(int levelNum)
: levelNumber{levelNum} {}

Block *Level::getSpecificBlock(string blockLetter) {
	char firstLetter = blockLetter[0];
	if (firstLetter == 'I') {
		return new BlockI{levelNumber};
	}
	else if (firstLetter == 'J') {
		return new BlockJ{levelNumber};
	}
	else if (firstLetter == 'L') {
		return new BlockL{levelNumber};
	}
	else if (firstLetter == 'O') {
		return new BlockO{levelNumber};
	}
	else if (firstLetter == 'S') {
		return new BlockS{levelNumber};
	}
	else if (firstLetter == 'Z') {
		return new BlockZ{levelNumber};
	}
	else {
		return new BlockT{levelNumber};
	}
}


int Level::getLevelNumber() const {
	return levelNumber;
}
