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
	gameBoard->init();
	while (!gameFinished and (!cin.eof())) {
		// TODO: what happens at EOF signal?
		cin >> command;
		cout << "Command: \'" << command << "\'" << endl;
		execute(command);
		cout << *textDisplay << endl;
	}

	// TODO: show score, highscore and stuff??
}


// Big 5 + ctor -------------------------------------------

Quadris::Quadris()
: textDisplay{new TextDisplay{}}, 
gameBoard{new GameBoard{textDisplay}}
{}


Quadris::~Quadris() {
	delete textDisplay;
	textDisplay = nullptr;
	delete gameBoard;
	gameBoard = nullptr;
}


