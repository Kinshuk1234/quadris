#ifndef CELL_H
#define CELL_H

#include "celldata.h"
#include "pos.h"
#include "subject.h"

class Cell : public Subject<CellData> { // Subject to textdisplay
	Pos position;
	char blockType;

public:
	void set(char newBlockType);
	void clear();
	char getLetter() const;
	void setRow(int i);
	void setPos(Pos newPos);
	Pos getPosition() const;

	// Observer
	CellData getData() override;

	// Big 5 + ctor
	Cell(int x, int y);
	Cell(const Cell &other);
	Cell(Cell &&other);
	Cell &operator=(const Cell &other);
	Cell &operator=(Cell &&other) = delete;

	~Cell();

};


#endif
