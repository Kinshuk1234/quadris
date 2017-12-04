#ifndef BLOCK_DOT_H
#define BLOCK_DOT_H

#include "block.h"
#include <vector>

class BlockDot : public Block {
	char myType;
public:
	// ctors
	BlockDot(int levelCreated, bool isHeavy = false);
	BlockDot(const BlockDot &other) = delete;
	BlockDot(BlockDot &&other) = delete;
	BlockDot &operator=(const BlockDot &other) = delete;
	BlockDot &operator=(BlockDot &&other) = delete;
	~BlockDot() = default;

	// other methods
	
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override; // USED
	char getLetter() override; // USED
};

#endif


