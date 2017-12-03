#ifndef BLOCK_O_H
#define BLOCK_O_H

#include "block.h"
#include <vector>

class BlockO : public Block {
	char myType;
public:
	// ctors
	BlockO(int levelCreated, bool isHeavy = false);
	BlockO(const BlockO &other) = delete;
	BlockO(BlockO &&other) = delete;
	BlockO &operator=(const BlockO &other) = delete;
	BlockO &operator=(BlockO &&other) = delete;
	~BlockO() = default;

	// overrides
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override; // USED
	char getLetter() override; // USED
	
};


#endif

