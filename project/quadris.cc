#include <memory>
#include "quadris.h"
#include "gameboarddata.h"


// TEMP:
#include <iostream>

using namespace std;


void Quadris::init() {
	// TODO: initialize the game object
	if(textOnly) {
		textDisplay = new TextDisplay{};
		//graphicsdisplay = nullptr;
	} else {
		textDisplay = new TextDisplay{};
		//graphicsdisplay = new GraphicsDisplay{};
	}
	// add graphicsDisplay too
	gameBoard = new GameBoard{textDisplay,level,seed,filename};
	this->attach(gameBoard); // This inherits from CommandInterpreter
	initGame();
}

void Quadris::initGame() {

	cout << "initgame() starts" << endl;
	string command = "";

	gameBoard->init();

	cout << "gameBoard->init() reached" << endl;
	// TODO: attach Graphics display to cells
	// TODO: graphics display output
	GameBoardData gbData = gameBoard->getData();
	while (!gbData.gameOver and (!cin.eof())) {
		cout << *textDisplay << endl;
		cin >> command;
		if (cin.eof()) {
			break;
		}
		execute(command);
		// TODO: graphics display output
	}

	// TODO: show score, highscore and stuff?? // In the displays
}

// void Quadris::notify(Subject<GameBoardData> &notifier) {

// }

////////////COMMAND-LINE ARGUMENTS//////////////

void Quadris::startLevel(int startLevel) {
	if(startLevel>4) {
		level = 4;
	} else if(startLevel<0) {
		level = 0;
	} else {
		level = startLevel;
	}
}

void Quadris::setSeed(int seedNo) {
	seed = seedNo;
}

void Quadris::setFilename(string newFilename) {
	filename = newFilename;
}

void Quadris::isGraphics(bool textOnlyDisplay) {
	if(textOnlyDisplay) {
		textOnly = true;
	} else {
		textOnly = false;
	}
}

// Big 5 + ctor -------------------------------------------


Quadris::~Quadris() {
	delete textDisplay;
	textDisplay = nullptr;
	delete gameBoard;
	gameBoard = nullptr;
	// delete graphicsdisplay;
	// graphicsdisplay = nullptr;
}


