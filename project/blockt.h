#ifndef BLOCK_T_H
#define BLOCK_T_H

#include "block.h"
#include <vector>

class BlockT : public Block {
	char myType;
public:
	// ctors
	BlockT();
	BlockT(const BlockT &other) = delete;
	BlockT(BlockT &&other) = delete;
	BlockT &operator=(const BlockT &other) = delete;
	BlockT &operator=(BlockT &&other) = delete;
	~BlockT() = default;

	// overrides
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override; // USED
	char getLetter() override; // USED
	
};


#endif

