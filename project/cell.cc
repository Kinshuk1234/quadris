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
	notifyAll();
}

void Cell::clear() {
	set('-'); // TODO: set to appropriate empty space character
}

char Cell::getLetter() const {
	return blockType;
}

void Cell::setRow(int i) {
	position.y = i;
}

void Cell::setPos(Pos newPos) {
	position.x = newPos.x;
	position.y = newPos.y;
	notifyAll();
}

Pos Cell::getPosition() const {
	return position;
}

// Subject/Observer
CellData Cell::getData() {
	CellData cd = {blockType, position};
	return cd;
}


// Big 5 + ctor -------------------------

Cell::Cell(int x, int y)
: position{x, y}, blockType{'-'} {/* CTOR BODY */}


Cell::Cell(const Cell &other)
: Subject{other}, position{other.position}, blockType{other.blockType} {/* COPY CTOR BODY */}

Cell::Cell(Cell &&other)
: Subject{other}, /* TODO: Copy superclasses (i.e. Subject) */position{other.position}, blockType{other.blockType} {/* COPY CTOR BODY */}

Cell::~Cell() {
	
}

Cell &Cell::operator=(const Cell &other) {
	position = other.getPosition();
	blockType = other.getLetter();
	return *this;
}

