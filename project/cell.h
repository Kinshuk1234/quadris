#ifndef CELL_H
#define CELL_H

#include "subject.h"
#include "celldata.h"

class Cell : public Subject<CellData> { // Subject to textdisplay
	int r, c;
	char blockType;

public:

	CellData getData() const override;
	void set(char newBlockType);

	// Big 5 + ctor
	Cell(int x, int y);
	Cell(const Cell &other);
	Cell(Cell &&other);
	Cell &operator=(const Cell &other) = delete;
	Cell &operator=(Cell &&other) = delete;

	~Cell();

};


#endif
