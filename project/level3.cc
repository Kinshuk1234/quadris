#include "level3.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
using namespace std;

Level3::Level3(int seed) : seed{seed} {};

Block* Level3::getBlock() {
	srand(seed);
	int num = (rand() % 9);
	if ((num == 0) || (num == 1)) return new BlockS;
	else if ((num == 2) || (num == 3)) return new BlockZ;
	else if (num == 4) return new BlockT;
	else if (num == 5) return new BlockI;
	else if (num == 6) return new BlockJ;
	else if (num == 7) return new BlockL;
	else return new BlockO;
}

Level3::~Level3() {}

