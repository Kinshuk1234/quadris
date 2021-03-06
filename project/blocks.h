#ifndef BLOCK_S_H
#define BLOCK_S_H

#include "block.h"
#include <vector>

class BlockS : public Block {
	char myType;
public:
	// ctors
	BlockS(int levelCreated, bool isHeavy = false);
	BlockS(const BlockS &other) = delete;
	BlockS(BlockS &&other) = delete;
	BlockS &operator=(const BlockS &other) = delete;
	BlockS &operator=(BlockS &&other) = delete;
	~BlockS() = default;

	// overrides
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override;
	char getLetter() override;
	
};


#endif

