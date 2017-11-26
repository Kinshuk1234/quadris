#include "commandinterpreter.h"
#include "scoreboard.h"
#include "textdisplay.h"



class Quadris {
	CommandInterpreter cmdInterpreter;
	ScoreBoard scoreBoard;
	TextDisplay textDisplay;
	// GameBoard gameBoard;

	
public:
	void init();
	// Big 5
	Quadris();

private:
	void runGameLoop();

};