#ifndef L_BLOCK_H
#define L_BLOCK_H

#include "block.h"
#include <vector>

class LBlock : public Block {
public:
	LBlock() = default;
	LBlock(const LBlock &other) = delete;
	LBlock(LBlock &&other) = delete;
	LBlock &operator=(const LBlock &other) = delete;
	LBlock &operator=(LBlock &&other) = delete;
	~LBlock() = default;
};


#endif


