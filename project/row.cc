#include "row.h"


// Other Methods ------------------------

void Row::add_cell(Cell c) {
	rowOfCells.emplace_back(c);
}



// Big 5 + ctor -------------------------

Row::Row()
: rowOfCells{} {}

Row::Row(Row &&other)
: rowOfCells{other.rowOfCells} {}

