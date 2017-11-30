#ifndef BLOCK_I_H
#define BLOCK_I_H

#include "block.h"
#include <vector>

class BlockI : public Block {
	char myType;
public:
	// ctors
	BlockI();
	BlockI(const BlockI &other) = delete;
	BlockI(BlockI &&other) = delete;
	BlockI &operator=(const BlockI &other) = delete;
	BlockI &operator=(BlockI &&other) = delete;
	~BlockI() = default;

	// other methods
	
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override; // USED
	char getLetter() override; // USED
};


#endif
