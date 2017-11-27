#include "commandinterpreter.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>

#include <iostream>

using namespace std;



// Other Methods ------------------------


istream &operator>>(istream &in, vector<string> &vec){
	string cmd = "";

	in >> cmd;
	while (cmd != "done") {
		vec.emplace_back(cmd);
		in >> cmd;
	}
	return in;
}


void CommandInterpreter::addNewCommand(string commandName, istream &in) {
	// TODO: check if the command name exists already, if so, then throw error
	// TODO: add the list of commands
	// TODO: check for the list end keyword to end the command list
	// TODO: then, add the macro to the map

	// TODO: check if command is not part of the list initially! Throw error if so
	cList[commandName] = {};
	in >> cList[commandName];
}

void CommandInterpreter::execute(string command) {
	currentCommand = command;
	notifyAll();
}

vector<string> CommandInterpreter::getData() {
	auto p = cList[currentCommand];
	return p;
}


// Big 5 + ctor ------------------------

CommandInterpreter::CommandInterpreter()
: cList{}, currentCommand{} {
	// TODO: make the usual commands
	cList["left"] = {"left"};
	cList["right"] = {"right"};
	cList["down"] = {"down"};
	cList["counterclockwise"] = {"counterclockwise"};
	cList["clockwise"] = {"clockwise"};
	// TODO: add more usual commands...
}



