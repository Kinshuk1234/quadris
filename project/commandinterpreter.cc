#include "commandinterpreter.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>

#include <iostream>

using namespace std;

// Other Methods ------------------------


istream &operator>>(istream &in, vector<string> &vec){
	// TODO: check if the command name exists already, if so, then throw error
	// TODO: make sure that when taking in the list, the command is only a command part of the game
	// i.e. can't add the newcom command in the list.
	// TODO: make sure commands in list are valid!
	// TODO: if commands are incomplete, use algorithm to use which one it could be:
	// i.e. lef --> left and NOT levelup
	// TODO: add the list of commands
	// TODO: check for the list end keyword to end the command list
	// TODO: then, add the macro to the map

	// TODO: check if command is not part of the list initially! Throw error if so
	string cmd = "";

	in >> cmd;
	while (cmd != "done") {
		vec.emplace_back(cmd);
		in >> cmd;
	}
	return in;
}


void CommandInterpreter::execute(string c) {
	// cout << "Given command: " << c << endl;
	string command = getFullCommand(c);
	// cout << "Actual command: " << command << endl;

	if (command == "") {
		cout << "Command does NOT exist" << endl;
		return;
	}

	if (cList[command].size() != 0) {
		if (command == "newcom") {
			// TOOD: make a new command
			string newCommandName;
			cout << "New command name: ";
			cin >> newCommandName;
			if (cList[newCommandName].size() == 0) {
				cin >> cList[command]; // from stdin
			}
			return;
		} else if (command == "...........") {
			// TODO: do something NOT related to the gameboard
		}
		// Gameboard related commands
		currentCommand = command;
		notifyAll();
	}
}

vector<string> CommandInterpreter::getData() {
	auto p = cList[currentCommand];
	return p;
}

string CommandInterpreter::getFullCommand(string incCommand) {
	int score = 0;
	int isAmbiguous = true;
	string actualCommand = "";
	for (auto &p : cList) {
		string key = p.first;
		int i = 0;
		while ((i < incCommand.length()) and 
			(i < key.length())
			and (incCommand[i] == key[i])) {
			i++;
		}
		if (i > score) {
			isAmbiguous = false;
			score = i;
			actualCommand = key;
		} else if (i == score) {
			isAmbiguous = true;
		}
	}
	if (isAmbiguous) {
		return "";
	}
	return actualCommand;
}

// Big 5 + ctor ------------------------

CommandInterpreter::CommandInterpreter()
: cList{}, currentCommand{} {
	// TODO: make the usual commands
	cList["left"] = {"left"};
	cList["right"] = {"right"};
	cList["down"] = {"down"};
	cList["drop"] = {"drop"};
	cList["levelup"] = {"levelup"};
	cList["restart"] = {"restart"};
	cList["counterclockwise"] = {"counterclockwise"};
	cList["clockwise"] = {"clockwise"};
	cList["newcom"] = {"newcom"};
	cList["hint"] = {"hint"};
	// TODO: add more usual commands...
}



