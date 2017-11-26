#include "textdisplay.h"
#include <vector>
#include <iostream>

using namespace std;


TextDisplay::TextDisplay()
: grid{} {
	for (int i = 0; i < 15; i++) {
		grid.emplace_back();
		for (int j = 0; j < 11; j++) {
			grid.back().emplace_back('-');
		}
	}
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	auto &grid = td.grid;
	for (auto it = grid.begin(); it != grid.end(); ++it) {
		for (auto innerIt = it->begin(); innerIt != it->end(); ++innerIt) {
			out << *innerIt;
		}
		out << endl;
	}

	return out;
}


