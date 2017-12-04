#include "level1.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
#include <ctime>
using namespace std;

Level1::Level1(int seed) : seed{seed} {};

Block* Level1::getBlock() {
	srand(time(0));
	int num = (rand() % 12);
	if (num == 0) return new BlockS{getLevelNumber()};
	else if (num == 1) return new BlockZ{getLevelNumber()};
	else if ((num == 2) || (num == 3)) return new BlockT{getLevelNumber()};
	else if ((num == 4) || (num == 5)) return new BlockI{getLevelNumber()};
	else if ((num == 6) || (num == 7)) return new BlockJ{getLevelNumber()};
	else if ((num == 8) || (num == 9)) return new BlockL{getLevelNumber()};
	else return new BlockO{getLevelNumber()};
}

Level1::~Level1() {}


int Level1::getLevelNumber() const {
	return 1;
}
