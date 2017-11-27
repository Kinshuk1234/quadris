#include "levelzero.h"
#include "block.h"
#include "lblock.h"

Block *LevelZero::getBlock() const {
	// TODO: return a random block, according to this level
	Block *newBlock = new LBlock{};
	return newBlock;
}

