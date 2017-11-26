#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H
#include <vector>
#include <map>


class CommandInterpreter { // TODO: inherit from subject
	std::map<std::string, std::vector<std::string>> cList;

public:
	void addNewCommand(std::string commandName); // add a macro command

	// Big 5 + ctor
	CommandInterpreter(); // main constructor
	CommandInterpreter(const CommandInterpreter &other) = delete;
	CommandInterpreter(CommandInterpreter &&other) = delete;
	CommandInterpreter &operator=(const CommandInterpreter &other) = delete;
	CommandInterpreter &operator=(CommandInterpreter &&other) = delete;
};

#endif

