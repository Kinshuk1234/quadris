#include <memory>
#include "quadris.h"
#include "gameboarddata.h"
// #include "graphicsdisplay.h"


// TEMP:
#include <iostream>

using namespace std;

Quadris::Quadris (bool bonusEnabled, int seed, bool graphicsEnabled, string filename, int startLevel)
:CommandInterpreter{bonusEnabled},
 textDisplay{new TextDisplay{}},
  gameBoard{NULL},
   level{startLevel},
    seed{seed},
     filename{filename}//, graphicsDisplay{graphicsEnabled ? nullptr : nullptr}
{ 
 	if (startLevel > 4) { level = 4; }
 	else if (startLevel < 0) { level = 0;}
 	else { level = startLevel; }
}

void Quadris::init() {
	// add graphicsDisplay too
	gameBoard = new GameBoard{textDisplay,level,seed,filename, bonusEnabled};
	this->attach(gameBoard); // This inherits from CommandInterpreter
	string command = "";

	gameBoard->init();
	// TODO: attach Graphics display to cells
	// TODO: graphics display output
	while (!cin.eof()) {
		cout << *textDisplay << endl;
		cin >> command;
		if (cin.eof()) {
			break;
		}
		execute(command);
		// TODO: graphics display output
	}
}

////////////COMMAND-LINE ARGUMENTS//////////////

// Big 5 + ctor -------------------------------------------


Quadris::~Quadris() {
	delete textDisplay;
	textDisplay = nullptr;
	delete gameBoard;
	gameBoard = nullptr;
	// delete graphicsdisplay;
	// graphicsdisplay = nullptr;
}


