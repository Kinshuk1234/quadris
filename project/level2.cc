#include "level2.h"

using namespace std;

Level2::Level2(int seed) : seed{seed} {};

Block* Level2::getBlock() {
	srand(seed);
	int num = (rand() % 7);
	if (num == 0) return new BlockS;
	else if (num == 1) return new BlockZ;
	else if (num == 2) return new BlockT;
	else if (num == 3) return new BlockI;
	else if (num == 4) return new BlockJ;
	else if (num == 5) return new BlockL;
	else return new BlockO;
}

Level2::~Level2() {}
