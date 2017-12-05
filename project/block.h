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
	bool isDropped;
	int levelCreated;
	bool isHeavy;

	int turnCount = 0;

	virtual std::vector<std::vector<Pos>> getOrientationsAt(Pos refPoint) const = 0;

public:

	virtual char getLetter() = 0; // public
	
	// Gets the orientation
	std::vector<Pos> getOrPtsOf(Pos givenRefPoint, int givenOrientation) const; // public
	
	void setInitialOrientation(int initOrientation); // public 
	int getCurrentOr() const; // public 
	void setCurrentOr(int newO); // public 
	
	Pos getRefPoint(int o) const; // public 
	void setRefPoint(Pos newRefPoint); // public

	
	void setDropped(bool dropped); // public
	void removeCellsAt(int row); // public
	int getLevelCreated() const; // public
	bool getIsHeavy() const; // public
	void turnCountAddOne(); // public
	int getTurnCount(); // public

	// Big 5 + ctor
	Block(int levelCreated, bool isHeavy = false);
	Block(const Block &other) = delete;
	Block(Block &&other) = delete;
	Block &operator=(const Block &other) = delete;
	Block &operator=(Block &&other) = delete;
	virtual ~Block();


};


#endif

