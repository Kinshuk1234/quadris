#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>

#include "commandinterpreter.h"
#include "scoreboard.h"
#include "textdisplay.h"
#include "gameboard.h"




class Quadris {
	CommandInterpreter cmdInterpreter;
	ScoreBoard scoreBoard;
	TextDisplay *textDisplay; // Change to smart pointer (i.e. unique_ptr, shared_ptr)
	GameBoard gameBoard;
	
public:
	void init();

	// Big 5 + ctor
	Quadris();
	Quadris(const Quadris &other) = delete;
	Quadris(Quadris &&other) = delete;
	Quadris &operator=(const Quadris &other) = delete;
	Quadris &operator=(Quadris &&other) = delete;

private:
	void runGameLoop();

};

#endif


