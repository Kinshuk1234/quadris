#ifndef BLOCK_S_H
#define BLOCK_S_H

#include "block.h"
#include <vector>

class BlockS : public Block {
public:
	// ctors
	BlockS() = default;
	BlockS(const BlockS &other) = delete;
	BlockS(BlockS &&other) = delete;
	BlockS &operator=(const BlockS &other) = delete;
	BlockS &operator=(BlockS &&other) = delete;
	~BlockO() = default;

	// other methods
};


#endif

