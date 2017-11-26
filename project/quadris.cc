#include "quadris.h"


// TEMP:
#include <iostream>

using namespace std;

Quadris::Quadris()
: cmdInterpreter{} {

}

void Quadris::init() {
	// TODO: initialize the game object
	runGameLoop();
}

void Quadris::runGameLoop() {
	string command = "";

	bool gameFinished = false;

	while (!gameFinished) {
		cin >> command;
		// TODO: add actions...
		// TODO: Visitor pattern for commands with the game board.
	}
}
