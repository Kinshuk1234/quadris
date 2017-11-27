#ifndef LEVEL_H
#define LEVEL_H

class Block;

class Level {
public:
	virtual Block *getBlock() const = 0;
	virtual ~Level() = default;
};

#endif


