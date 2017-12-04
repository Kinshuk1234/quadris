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

Level3::Level3(int seed) : seed{seed} {};

Block* Level3::getBlock() {
	srand(time(0));
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

