#include "cell.h"
#include "subject.h"

#include <iostream>

using namespace std;

// Other Methods ------------------------

// Cell is a Subject

// CellData Cell::getData() {
// 	CellData cd {blockType, r, c};
// 	return cd;
// }

void Cell::set(char newBlockType) {
	blockType = newBlockType;
	// notifyAll();
}

void Cell::clear() {
	set('-'); // TODO: set to appropriate empty space character
}

char Cell::getLetter() const {
	return blockType;
}


// Big 5 + ctor -------------------------

Cell::Cell(int r, int c)
: r{r}, c{c}, blockType{'-'} {/* CTOR BODY */}


Cell::Cell(const Cell &other)
: r{other.r}, c{other.c}, blockType{other.blockType} {/* COPY CTOR BODY */}

Cell::Cell(Cell &&other)
: /* TODO: Copy superclasses (i.e. Subject) */r{other.r}, c{other.c}, blockType{other.blockType} {/* COPY CTOR BODY */}

Cell::~Cell() {
	
}


