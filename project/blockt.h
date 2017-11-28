#ifndef BLOCK_T_H
#define BLOCK_T_H

#include "block.h"
#include <vector>

class BlockT : public Block {
public:
	// ctors
	BlockT();
	BlockT(const BlockT &other) = delete;
	BlockT(BlockT &&other) = delete;
	BlockT &operator=(const BlockT &other) = delete;
	BlockT &operator=(BlockT &&other) = delete;
	~BlockT() = default;

	// other methods
};


#endif

