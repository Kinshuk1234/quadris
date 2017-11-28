#ifndef BLOCK_L_H
#define BLOCK_L_H

#include "block.h"
#include <vector>

class BlockL : public Block {
public:
	// ctors
	BlockL() = default;
	BlockL(const BlockL &other) = delete;
	BlockL(BlockL &&other) = delete;
	BlockL &operator=(const BlockL &other) = delete;
	BlockL &operator=(BlockL &&other) = delete;
	~BlockL() = default;

	// other methods
};


#endif


