#include "row.h"
#include "cell.h"



// Other Methods ------------------------

void Row::emplaceCell(Cell c) {
	rowOfCells.emplace_back(c);
}

Cell &Row::getCellAt(int index) {
	return rowOfCells.at(index);
}



// Big 5 + ctor -------------------------

Row::Row()
: rowOfCells{} {}

Row::Row(Row &&other)
: rowOfCells{other.rowOfCells} {}

