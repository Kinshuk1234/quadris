#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H
#include <vector>
#include <map>
#include "subject.h"

class CommandInterpreter : public Subject<std::vector<std::string>> { // TODO: inherit from subject
	std::map<std::string, std::vector<std::string>> cList;
	std::string currentCommand;

public:
	void execute(std::string command);

	std::vector<std::string> getData() override;
	int getScore(std::string full, std::string sub); // private

	// Big 5 + ctor
	CommandInterpreter(); // main constructor
	CommandInterpreter(const CommandInterpreter &other) = delete;
	CommandInterpreter(CommandInterpreter &&other) = delete;
	CommandInterpreter &operator=(const CommandInterpreter &other) = delete;
	CommandInterpreter &operator=(CommandInterpreter &&other) = delete;

	friend std::istream &operator>>(std::istream &in, std::vector<std::string> &vec);

private:
	std::string getFullCommand(std::string incCommand);
};

#endif

