#include "level3.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
#include <ctime>
using namespace std;

Level3::Level3(int seed, bool isRandom) : seed{seed}, isRandom{isRandom}, v{}, blockIndex{0} {
	srand(seed);
	if (isRandom == false) {
		string filename;
		cin >> filename;
		char blockType;
		ifstream f{filename};
		while(f >> blockType) {
			v.emplace_back(blockType);
		}
	}
}

Block* Level3::getBlock() {
	if (isRandom == false) {
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
	int num = (rand() % 9);
	if ((num == 0) || (num == 1)) return new BlockS{getLevelNumber(), true};
	else if ((num == 2) || (num == 3)) return new BlockZ{getLevelNumber(), true};
	else if (num == 4) return new BlockT{getLevelNumber(), true};
	else if (num == 5) return new BlockI{getLevelNumber(), true};
	else if (num == 6) return new BlockJ{getLevelNumber(), true};
	else if (num == 7) return new BlockL{getLevelNumber(), true};
	else return new BlockO{getLevelNumber(), true};
}

Level3::~Level3() {}

int Level3::getLevelNumber() const {
	return 3;
}

