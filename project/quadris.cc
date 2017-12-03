#include <memory>
#include "quadris.h"
#include "gameboarddata.h"


// TEMP:
#include <iostream>

using namespace std;


void Quadris::init() {
	// TODO: initialize the game object
	this->attach(gameBoard); // This inherits from CommandInterpreter
	initGame();
}

void Quadris::initGame() {
	string command = "";

	gameBoard->init();
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

void notify(Subject<GameBoardData> &notifier) {

}

// Big 5 + ctor -------------------------------------------

Quadris::Quadris()
: textDisplay{new TextDisplay{}}, 
gameBoard{new GameBoard{textDisplay}}
{}

Quadris::Quadris(int gridSize, int winSize) : 
graphicsdisplay{new GraphicsDisplay(gridSize, winSize)},
gameBoard{new GameBoard{graphicsdisplay}} {}

Quadris::~Quadris() {
	delete textDisplay;
	textDisplay = nullptr;
	delete gameBoard;
	gameBoard = nullptr;
	delete graphicsdisplay;
	graphicsdisplay = nullptr;
}


