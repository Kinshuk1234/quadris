#include <iostream>
#include <vector>




class TextDisplay {
	std::vector<std::vector<char>> grid;

public:
	TextDisplay(); // Ctor


	friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

