#ifndef POS_H
#define POS_H

#include <sstream>

struct Pos {
	int x;
	int y;
};

bool operator==(const Pos &lhs, const Pos &rhs);
std::ostream &operator<<(std::ostream &out, const Pos &rhs);

#endif

