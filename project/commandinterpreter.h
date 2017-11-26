#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H
#include <vector>
#include <map>


class CommandInterpreter { // TODO: inherit from subject
	std::map<std::string, std::vector<std::string>> cList;

public:
	CommandInterpreter(); // main constructor
	void addNewCommand(std::string commandName); // add a macro command
};

#endif

