#ifndef ROW_H
#define ROW_H

#include <vector>

#include "cell.h"

class Row {
	std::vector<Cell> rowOfCells;


public:
	void emplaceCell(Cell c);

	Cell &getCellAt(int col);

	// Big 5 + ctor
	Row();
	Row(const Row &other) = delete;
	Row(Row &&other);
	Row &operator=(const Row &other) = delete;
	Row &operator=(Row &&other) = delete;
};

#endif

