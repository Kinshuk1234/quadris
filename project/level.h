#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

class Block;
class Level {
public:
	virtual Block *getBlock() = 0;
	virtual ~Level() = default;
};

Level::~Level() {}

#endif
