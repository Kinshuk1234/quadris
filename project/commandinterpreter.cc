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

	int mult=0;
	string textC;
	string finalC;

	istringstream ss{c};

	ss >> textC;

	istringstream ssMult{textC};

	if(ssMult>>mult) {
		ssMult >> finalC;
	} else {
		finalC = textC;
		mult=-1;
	}

	string command = getFullCommand(finalC);

	if (command == "") {
		cout << "Command does NOT exist" << endl;
		return;
	}

	if (cList[command].size() != 0) {
		cout << "COMMAND: ";
		for (int m = 0; m < cList[command].size(); m++) {
			cout << cList[command].at(m) << " ";
		}
		cout << endl;
		if (command == "newcom") {
			// TOOD: make a new command
			string newCommandName;
			cout << "New command name: ";
			cin >> newCommandName;
			while (cList[newCommandName].size() != 0) {
				cout << "Command name already taken, please choose another: ";
				cin >> newCommandName;
			}
			string cmd = "";
			cin >> cmd;
			while (cmd != "done") {
				// TODO: add conditions on which cmds are addable if any
				cmd = getFullCommand(cmd);
				if (cmd != "") {
					cList[newCommandName].emplace_back(cmd);
				}
				cin >> cmd;
			}
			return;
		} else if (command == "...........") {
			// TODO: do something NOT related to the gameboard
		} else if (command == "rename") {
			string oldCommandName;
			string newCommandName;
			cin >> oldCommandName >> newCommandName;
			if (cList[oldCommandName].size() != 0) {

				while (cList[newCommandName].size() != 0 and newCommandName == "done") {
					cout << "Name already taken, please choose another: ";
					cin >> newCommandName;
				}
				cList[newCommandName] = cList[oldCommandName];
				cList.erase(oldCommandName);
			} else {
				cout << "Command Doesn't exist yet." << endl;
			}
			return;
		}
		// Gameboard related commands

		if(command=="restart" || command=="hint" || command=="norandom" || command=="random") {
			currentCommand = command;
			notifyAll();
		} else if(mult==-1) {
			currentCommand = command;
			notifyAll();
		} else {
			for(int i=0; i<mult; ++i) {
				currentCommand = command;
				notifyAll();
			}
		}
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
		int newScore = getScore(p.first, incCommand);
		if (newScore > score) {
			isAmbiguous = false;
			actualCommand = p.first;
			score = newScore;
		} else if (newScore == score) {
			isAmbiguous = true;
		}
		// string key = p.first;
		// int i = 0;
		// while ((i < incCommand.length()) and 
		// 	(i < key.length())
		// 	and (incCommand[i] == key[i])) {
		// 	i++;
		// }
		// if (i > score) {
		// 	isAmbiguous = false;
		// 	score = i;
		// 	actualCommand = key;
		// } else if (i == score) {
		// 	isAmbiguous = true;
		// }
	}
	if (isAmbiguous) {
		return "";
	}
	return actualCommand;
}

int CommandInterpreter::getScore(string full, string sub) {
	int j = 0;
	for (int i = 0; i < sub.length(); i++) {
		if (full[i] == sub[i]) {
			j++;
		} else {
			j = 0;
			break;
		}
	}
	return j;
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
	cList["leveldown"] = {"leveldown"};
	cList["restart"] = {"restart"};
	cList["counterclockwise"] = {"counterclockwise"};
	cList["clockwise"] = {"clockwise"};
	cList["newcom"] = {"newcom"};
	cList["hint"] = {"hint"};
	cList["rename"] = {"rename"};
	cList["norandom"] = {"norandom"};
	cList["random"] = {"random"};
	cList["sequence"] = {"sequence"};
	cList["I"] = {"I"};
	cList["L"] = {"L"};
	cList["J"] = {"J"};
	cList["O"] = {"O"};
	cList["S"] = {"S"};
	cList["Z"] = {"Z"};
	cList["T"] = {"T"};
	// TODO: add more usual commands...
}



