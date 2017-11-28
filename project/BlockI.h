#ifndef BLOCK_I_H
#define BLOCK_I_H

#include "block.h"
#include <vector>

class BlockI : public Block {
public:
	// ctors
	BlockI();
	BlockI(const BlockI &other) = delete;
	BlockI(BlockI &&other) = delete;
	BlockI &operator=(const BlockI &other) = delete;
	BlockI &operator=(BlockI &&other) = delete;
	~BlockI() = default;

	// other methods
	void rotate_cw();
	void rotate_ccw();
};


#endif