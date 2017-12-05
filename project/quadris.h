#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>

#include "commandinterpreter.h"
#include "textdisplay.h"
#include "gameboard.h"
// #include "graphicsdisplay.h"



class Quadris : public CommandInterpreter {
	TextDisplay *textDisplay; // Change to smart pointer (i.e. unique_ptr, shared_ptr)
	// GraphicsDisplay *graphicsDisplay;
	GameBoard *gameBoard;
	
	//COMMAND-LINE ARGUMENTS
	int level;
	int seed;
	std::string filename;
	bool graphicsEnabled;
	
public:
	void init();

	// Big 5 + ctor
	Quadris(bool bonusEnabled, int seed, bool graphicsEnabled, std::string filename, int startLevel);


	Quadris(const Quadris &other) = delete;
	Quadris(Quadris &&other) = delete;
	Quadris &operator=(const Quadris &other) = delete;
	Quadris &operator=(Quadris &&other) = delete;
	~Quadris();

};

#endif


