#ifndef CELL_H
#define CELL_H

#include "celldata.h"

class Cell { // Subject to textdisplay
	int r, c;
	char blockType;

public:
	void set(char newBlockType);
	void clear();
	char getLetter() const;


	// Big 5 + ctor
	Cell(int x, int y);
	Cell(const Cell &other);
	Cell(Cell &&other);
	Cell &operator=(const Cell &other) = delete;
	Cell &operator=(Cell &&other) = delete;

	~Cell();

};


#endif
