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
	std::vector<Pos> refPoints;
	int currOrientation; // One of 0, 1, 2, 3

public:

	// Big 5 + ctor
	Block();
	Block(const Block &other) = delete;
	Block(Block &&other) = delete;
	Block &operator=(const Block &other) = delete;
	Block &operator=(Block &&other) = delete;
	virtual ~Block();

	// other methods
	// std::vector<Pos> getOrientationPoints(int i);
	// void translateX(bool toRight); 
	// void translateY(); 
	// void checkOrientation(const Block &b);
	void rotate(bool clockwise); // USED

	void lockOrientationsAbout(Pos refPoint); // USED
	void setRefPoint(Pos newRefPoint); // USED
	void setInitialOrientation(int initOrientation); // USED

	void setOrientation(int i); // USED
	int getCurrentOrientation(); // USED
	std::vector<Pos> getCurrOrientationPoints(); // USED
	Pos getRefPoint() const;
	std::vector<Pos> getOrientationAtPoint(int orValue);

	virtual char getLetter() = 0; // USED
	std::vector<Pos> getOrientationWith(Pos otherRefPoint, int otherOrientation) const; // USED
	virtual std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const = 0; // USED
};


#endif

