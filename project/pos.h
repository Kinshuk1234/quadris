#ifndef POS_H
#define POS_H

#include <sstream>

struct Pos {
	int x;
	int y;
	Pos &operator+(const Pos &rhs);
};

bool operator==(const Pos &lhs, const Pos &rhs);
std::ostream &operator<<(std::ostream &out, const Pos &rhs);

Pos operator+(const Pos &lhs, const Pos &rhs);

#endif

