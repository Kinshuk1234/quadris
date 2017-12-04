#include "level2.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
#include <ctime>
using namespace std;

Level2::Level2(int seed) : seed{seed} {
	srand(seed);
};

Block* Level2::getBlock() {
	int num = (rand() % 7);
	if (num == 0) return new BlockS{getLevelNumber()};
	else if (num == 1) return new BlockZ{getLevelNumber()};
	else if (num == 2) return new BlockT{getLevelNumber()};
	else if (num == 3) return new BlockI{getLevelNumber()};
	else if (num == 4) return new BlockJ{getLevelNumber()};
	else if (num == 5) return new BlockL{getLevelNumber()};
	else return new BlockO{getLevelNumber()};
}

Level2::~Level2() {}


int Level2::getLevelNumber() const {
	return 2;
}
