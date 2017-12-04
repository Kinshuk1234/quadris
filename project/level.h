#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

class Block;

class Level {
	int levelNumber;
public:
	Level(int levelNum);
	Block *getSpecificBlock(std::string blockLetter);
	virtual Block *getBlock() = 0;
	virtual ~Level();
	virtual int getLevelNumber() const;
};

#endif
