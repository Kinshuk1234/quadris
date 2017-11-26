#ifndef TEXT_DISPLAY_H
#define TEXT_DISPLAY_H

#include <iostream>
#include <vector>




class TextDisplay {
	std::vector<std::vector<char>> grid;

public:


	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);

	// Big 5 + ctor
	TextDisplay();
	TextDisplay(const TextDisplay &other) = delete;
	TextDisplay(TextDisplay &&other) = delete;
	TextDisplay &operator=(const TextDisplay &other) = delete;
	TextDisplay &operator=(TextDisplay &&other) = delete;
};

#endif
