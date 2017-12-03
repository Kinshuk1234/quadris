#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>

#include "commandinterpreter.h"
#include "textdisplay.h"
#include "gameboard.h"
//#include "graphicsdisplay.h"


class Quadris : public CommandInterpreter {
	TextDisplay *textDisplay; // Change to smart pointer (i.e. unique_ptr, shared_ptr)
	//	GraphicsDisplay *graphicsdisplay;
	GameBoard *gameBoard;
	
	//COMMAND-LINE ARGUMENTS
//protected:
	int level;
	int seed;
	std::string filename;
	bool textOnly;
	
public:
	void init();

	// Big 5 + ctor
	//  graphicsdisplay{NULL} add that too
	Quadris() : textDisplay{NULL}, gameBoard{NULL}, level{0}, seed{1}, filename{"sequence.txt"}, textOnly{false} {}


	Quadris(const Quadris &other) = delete;
	Quadris(Quadris &&other) = delete;
	Quadris &operator=(const Quadris &other) = delete;
	Quadris &operator=(Quadris &&other) = delete;
	~Quadris();

	// command-line arguments
	void startLevel(int startLevel=0);
	void setSeed(int seedNo=1);
	void setFilename(std::string newFilename="sequence.txt");
	void isGraphics(bool textOnlyDisplay=false);

private:
	void initGame();

};

#endif


