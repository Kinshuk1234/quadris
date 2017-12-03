#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>

#include "commandinterpreter.h"
#include "textdisplay.h"
#include "gameboard.h"
#include "graphicsdisplay.h"




class Quadris : public CommandInterpreter {
	TextDisplay *textDisplay; // Change to smart pointer (i.e. unique_ptr, shared_ptr)
	GraphicsDisplay *graphicsdisplay;
	GameBoard *gameBoard;
	
public:
	void init();

	// Big 5 + ctor
	Quadris();
	Quadris(int gridSize, int winSize);
	Quadris(const Quadris &other) = delete;
	Quadris(Quadris &&other) = delete;
	Quadris &operator=(const Quadris &other) = delete;
	Quadris &operator=(Quadris &&other) = delete;
	~Quadris();

private:
	void runGameLoop();

};

#endif


