#include "quadris.h"
#include <memory>

// TEMP:
#include <iostream>

using namespace std;

Quadris::Quadris()
: cmdInterpreter{}, scoreBoard{}, textDisplay{new TextDisplay{}}, gameBoard{new GameBoard{textDisplay}} {

}

void Quadris::init() {
	// TODO: initialize the game object
	cmdInterpreter.attach(gameBoard);
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
			scoreBoard.updateCurrentScoreWith(*gameBoard);
		} else if (command == "newcommand") {
			cout << "Taking new command..." << endl;
			string newc;
			cin >> newc;
			cmdInterpreter.addNewCommand(newc, cin);
		} else {
			cmdInterpreter.execute(command);
		}
	}
}


