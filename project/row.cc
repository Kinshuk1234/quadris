#include "row.h"



Row::Row()
: rowOfCells{} {}

Row::Row(Row &&other)
: rowOfCells{other.rowOfCells} {}

void Row::add_cell(Cell c) {
	rowOfCells.emplace_back(c);
}
