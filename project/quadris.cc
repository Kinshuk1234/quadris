#include "quadris.h"
#include <memory>

// TEMP:
#include <iostream>

using namespace std;

Quadris::Quadris()
: cmdInterpreter{}, scoreBoard{}, textDisplay{new TextDisplay{}}, gameBoard{textDisplay} {

}

void Quadris::init() {
	// TODO: initialize the game object
	runGameLoop();
}

void Quadris::runGameLoop() {
	string command = "";

	bool gameFinished = false;

	while (!gameFinished) {
		// TODO: what happens at EOF signal?
		cin >> command;
		cout << "Command: \'" << command << "\'" << endl;
		// TODO: add actions...
		// TODO: Visitor pattern for commands with the game board.
		// TODO: update scoreboard score in the END

		if (command == "drop") {
			// TODO: drop the piece if possible.
			scoreBoard.updateCurrentScoreWith(gameBoard);
		}
		
	}
}


