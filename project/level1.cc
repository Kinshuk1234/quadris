#include "level1.h"
#include "blocki.h"
#include "blockj.h"
#include "blockl.h"
#include "blocko.h"
#include "blocks.h"
#include "blockt.h"
#include "blockz.h"
using namespace std;

Level1::Level1(int seed) : seed{seed} {};

Block* Level1::getBlock() {
	srand(time(NULL)); // TODO: random function not working
	int num = (rand() % 12);
	if (num == 0) return new BlockS;
	else if (num == 1) return new BlockZ;
	else if ((num == 2) || (num == 3)) return new BlockT;
	else if ((num == 4) || (num == 5)) return new BlockI;
	else if ((num == 6) || (num == 7)) return new BlockJ;
	else if ((num == 8) || (num == 9)) return new BlockL;
	else return new BlockO;
}

Level1::~Level1() {}
