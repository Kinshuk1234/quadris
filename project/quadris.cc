#include <memory>
#include "quadris.h"



// TEMP:
#include <iostream>

using namespace std;


void Quadris::init() {
	// TODO: initialize the game object
	this->attach(gameBoard); // This inherits from CommandInterpreter
	runGameLoop();
}

void Quadris::runGameLoop() {
	string command = "";

	bool gameFinished = false;

	while (!gameFinished) {
		// TODO: what happens at EOF signal?
		cin >> command;
		cout << "Command: \'" << command << "\'" << endl;
		// TODO: update scoreboard score in the END
		execute(command);
		scoreBoard.updateCurrentScoreWith(*gameBoard);
		cout << *textDisplay << endl;
	}
}


// Big 5 + ctor -------------------------------------------

Quadris::Quadris()
: scoreBoard{}, 
textDisplay{new TextDisplay{}}, 
gameBoard{new GameBoard{textDisplay}}
{}


Quadris::~Quadris() {
	delete textDisplay;
	textDisplay = nullptr;
	delete gameBoard;
	gameBoard = nullptr;
}


