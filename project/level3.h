#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"

class Block;
class Level3 : public Level{
	public:
		Level3(int seed = 1);
		Block *getBlock() override;
		~Level3() = default;
	};

#endif
