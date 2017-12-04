#ifndef LEVEL4_H
#define LEVEL4_H

#include "level3.h"


class Level4 : public Level3 {

public:

	Level4(int seed = 1);

	int getLevelNumber() const;
};

#endif
