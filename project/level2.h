#ifndef LEVEL2_H
#define LEVEL2_H
#include "level.h"

class Block;
class Level2 : public Level{
	int seed;
	public:
		Level2(int seed = 1);
		Block *getBlock() override;
		~Level2();

		int getLevelNumber() const override;
};

#endif
