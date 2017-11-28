#ifndef BLOCK_H
#define BLOCK_H
#include "pos.h"
#include <vector>

class Block {
	// Orientations: 0 is North, 1 is East, 2 is South, 3 is West
	// To get the clockwise rotation orientation, get (currOrientation + 1) % 4
	// To get the counter-clockwise rotation orientation, get (currOrientation - 1) % 4
protected:
	std::vector<std::vector<Pos>> orientations;
	int currOrientation; // One of 0, 1, 2, 3
public:

	// Big 5 + ctor
	Block() = default;
	Block(const Block &other) = delete;
	Block(Block &&other) = delete;
	Block &operator=(const Block &other) = delete;
	Block &operator=(Block &&other) = delete;
	~Block() = default;

	// other methods
	void translateX(bool toRight);
	void translateY();
	void checkOrientation(const Block &b);
	void rotate_cw();
	void rotate_ccw();
};


#endif

