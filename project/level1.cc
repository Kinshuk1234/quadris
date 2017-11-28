#include "level1.h"

using namespace std;

Level1::Level1(int seed) : seed{seed} {};

Block* Level1::getBlock() {
	srand(seed);
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
