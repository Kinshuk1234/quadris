#include "cell.h"
#include "subject.h"


// Other Methods ------------------------

// Cell is a Subject

CellData Cell::getData() const {
	CellData cd{blockType, r, c};
	return cd;
}

void Cell::set(char newBlockType) {
	blockType = newBlockType;
	notifyAll();
}


// Big 5 + ctor -------------------------

Cell::Cell(int r, int c)
: r{r}, c{c}, blockType{'-'} {/* CTOR BODY */}


Cell::Cell(const Cell &other)
: /* TODO: Copy superclasses (i.e. Subject) */r{other.r}, c{other.c} {/* COPY CTOR BODY */}

Cell::Cell(Cell &&other)
: /* TODO: Copy superclasses (i.e. Subject) */r{other.r}, c{other.c} {/* COPY CTOR BODY */}

Cell::~Cell() {
	
}


