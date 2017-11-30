#ifndef BLOCK_Z_H
#define BLOCK_Z_H

#include "block.h"
#include <vector>

class BlockZ : public Block {
	char myType;
public:
	// ctors
	BlockZ();
	BlockZ(const BlockZ &other) = delete;
	BlockZ(BlockZ &&other) = delete;
	BlockZ &operator=(const BlockZ &other) = delete;
	BlockZ &operator=(BlockZ &&other) = delete;
	~BlockZ() = default;

	// overrides
	std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const override; // USED
	char getLetter() override; // USED

};


#endif

