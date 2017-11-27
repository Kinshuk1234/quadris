#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include <iostream>
#include <vector>
#include "celldata.h"
#include "observer.h"

class Cell;

class TextDisplay : public Observer<CellData> {
	std::vector<std::vector<char>> grid;

public:
	void notify(Subject<CellData> &notifier) override;

	// Big 5 + ctor
	TextDisplay();
	TextDisplay(const TextDisplay &other) = delete;
	TextDisplay(TextDisplay &&other) = delete;
	TextDisplay &operator=(const TextDisplay &other) = delete;
	TextDisplay &operator=(TextDisplay &&other) = delete;

	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
