#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Block;
class Level3 : public Level{
	int seed;
	public:
		Level3(int seed = 1);
		Block *getBlock() override;
		~Level3();
	};

#endif
