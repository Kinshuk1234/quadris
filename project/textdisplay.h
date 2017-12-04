#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include <iostream>
#include <vector>
#include "celldata.h"
// #include "gameboarddata.h" // Don't need
#include "scoreboarddata.h"
#include "observer.h"

class Cell;

class TextDisplay : public Observer<CellData>, public Observer<ScoreBoardData> {
	std::vector<std::vector<char>> grid;
	int hiScore;
	int currentScore;
	int currentLevel;
	char nextBlockLetter;

public:
	void notify(Subject<CellData> &notifier) override;
	void notify(Subject<ScoreBoardData> &notifier) override;
	int getCurrentLevel() const;
	int getCurrentScore() const;
	int getHiScore() const;
	char getNextBlockLetter() const;

	// Big 5 + ctor
	TextDisplay();
	TextDisplay(const TextDisplay &other) = delete;
	TextDisplay(TextDisplay &&other) = delete;
	TextDisplay &operator=(const TextDisplay &other) = delete;
	TextDisplay &operator=(TextDisplay &&other) = delete;

	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
