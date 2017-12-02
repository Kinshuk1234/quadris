#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include <iostream>
#include <vector>
#include "celldata.h"
#include "gameboarddata.h"
#include "observer.h"

class Cell;

class TextDisplay : public Observer<GameBoardData> {
	std::vector<std::vector<char>> grid;
	int hiScore;
	int currentScore;
	int currentLevel;

public:
	void notify(Subject<GameBoardData> &notifier) override;
	int getCurrentLevel() const;
	int getCurrentScore() const;
	int getHiScore() const;

	// Big 5 + ctor
	TextDisplay();
	TextDisplay(const TextDisplay &other) = delete;
	TextDisplay(TextDisplay &&other) = delete;
	TextDisplay &operator=(const TextDisplay &other) = delete;
	TextDisplay &operator=(TextDisplay &&other) = delete;

	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
