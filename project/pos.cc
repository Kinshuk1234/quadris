#include "pos.h"

using namespace std;

bool operator==(const Pos &lhs, const Pos &rhs) {
	if ((lhs.x == rhs.x) and (lhs.y == rhs.y)) {
		return true;
	}
	return false;
}


ostream &operator<<(ostream &out, const Pos &rhs) {
	out << "(" << rhs.x << ", " << rhs.y << ")";
	return out;
}



Pos &Pos::operator+(const Pos &rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

