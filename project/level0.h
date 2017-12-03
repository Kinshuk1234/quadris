#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"


class Block;
class Level0 : public Level {
	std::vector<char> v;
	public:
		Level0(std::string filename = "sequence.txt");
		Block *getBlock() override;
		~Level0();

		int getLevelNumber() const override;
};

#endif
