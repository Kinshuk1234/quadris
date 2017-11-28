#ifndef BLOCK_Z_H
#define BLOCK_Z_H

#include "block.h"
#include <vector>

class BlockZ : public Block {
public:
	// ctors
	BlockZ();
	BlockZ(const BlockZ &other) = delete;
	BlockZ(BlockZ &&other) = delete;
	BlockZ &operator=(const BlockZ &other) = delete;
	BlockZ &operator=(BlockZ &&other) = delete;
	~BlockZ() = default;

	// other methods
};


#endif

