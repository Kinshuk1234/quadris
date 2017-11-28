#ifndef LEVEL1_H
#define LEVEL1_H
#include <cstdlib>
#include "level.h"

class Block;
class Level1 : public Level{
	public:
		Level1(int seed = 1);
		Block *getBlock() override;
		~Level1() = default;
};

#endif
