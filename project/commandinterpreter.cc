#include "commandinterpreter.h"
#include <vector>
#include <map>
using namespace std;

// TEMP
#include <iostream>


CommandInterpreter::CommandInterpreter()
: cList{} {
	// TODO: make the usual commands
	cList["left"] = {"left"};
	cList["right"] = {"right"};
	cList["down"] = {"down"};
	cList["counterclockwise"] = {"counterclockwise"};
	cList["clockwise"] = {"clockwise"};
}

void CommandInterpreter::addNewCommand(string commandName) {
	// TODO: check if the command name exists already, if so, then throw error
	// TODO: add the list of commands
	// TODO: check for the list end keyword to end the command list
	// TODO: then, add the macro to the map
}

