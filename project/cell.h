#ifndef CELL_H
#define CELL_H


class Cell { // Subject to textdisplay
	int r, c;

public:
	Cell(int x, int y);
	Cell(const Cell &other);
	Cell(Cell &&other);
	Cell &operator=(const Cell &other) = delete;
	Cell &operator=(Cell &&other) = delete;

};


#endif
