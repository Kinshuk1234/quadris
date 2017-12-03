#ifndef BLOCK_L_H
#define BLOCK_L_H

#include "block.h"
#include <vector>

class BlockL : public Block {
	char myType;
public:
	// ctors
	BlockL(int levelCreated, bool isHeavy = false);
	BlockL(const BlockL &other) = delete;
	BlockL(BlockL &&other) = delete;
	BlockL &operator=(const BlockL &other) = delete;
	BlockL &operator=(BlockL &&other) = delete;
	~BlockL() = default;

	// Overrides
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override; // USED
	char getLetter() override; // USED

};


#endif


