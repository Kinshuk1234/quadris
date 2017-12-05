#ifndef COMMAND_INTERPRETER_H
#define COMMAND_INTERPRETER_H
#include <vector>
#include <map>
#include "subject.h"
#include <fstream>

class CommandInterpreter : public Subject<std::vector<std::string>> { // TODO: inherit from subject
	std::map<std::string, std::vector<std::string>> cList;
	std::string currentCommand;

protected:
	bool bonusEnabled;
	void execute(std::string command);

public:

	std::vector<std::string> getData() override; // public

	// Big 5 + ctor
	CommandInterpreter(bool bonusEnabled1); // main constructor
	CommandInterpreter(const CommandInterpreter &other) = delete;
	CommandInterpreter(CommandInterpreter &&other) = delete;
	CommandInterpreter &operator=(const CommandInterpreter &other) = delete;
	CommandInterpreter &operator=(CommandInterpreter &&other) = delete;

	friend std::istream &operator>>(std::istream &in, std::vector<std::string> &vec);

private:

	int getMultiplier(std::string c); 
	std::string getFullCommand(std::string incCommand);
	int getScore(std::string full, std::string sub); // private
	std::string getCommand(std::string c);
};

#endif

