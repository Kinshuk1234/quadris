#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Block;
class Level3 : public Level{
	int seed;
	bool isRandom;
	int blockIndex;
	std::vector<char> v;
	public:
		Level3(int seed = 1, bool isRandom = true);
		Block *getBlock() override;
		~Level3();
	};

#endif
