#ifndef BLOCK_O_H
#define BLOCK_O_H

#include "block.h"
#include <vector>

class BlockO : public Block {
public:
	// ctors
	BlockO();
	BlockO(const BlockO &other) = delete;
	BlockO(BlockO &&other) = delete;
	BlockO &operator=(const BlockO &other) = delete;
	BlockO &operator=(BlockO &&other) = delete;
	~BlockO() = default;

	// other methods
};


#endif

