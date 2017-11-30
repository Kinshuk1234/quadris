#ifndef BLOCK_J_H
#define BLOCK_J_H

#include "block.h"
#include <vector>

class BlockJ : public Block {
	char myType;
public:
	// ctors
	BlockJ();
	BlockJ(const BlockJ &other) = delete;
	BlockJ(BlockJ &&other) = delete;
	BlockJ &operator=(const BlockJ &other) = delete;
	BlockJ &operator=(BlockJ &&other) = delete;
	~BlockJ() = default;

	// overrides
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override; // USED
	char getLetter() override; // USED
};


#endif

