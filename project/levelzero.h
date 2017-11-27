#ifndef LEVEL_ZERO_H
#define LEVEL_ZERO_H

#include "level.h"
#include "block.h"


class LevelZero : public Level {
public:
	Block *getBlock() const override;
	~LevelZero() = default;
};


#endif


