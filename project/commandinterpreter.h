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

public:
	void execute(std::string command);

	std::vector<std::string> getData() override;
	int getScore(std::string full, std::string sub); // private
	int getMultiplier(std::string c); 
	std::string getCommand(std::string c);

	// Big 5 + ctor
	CommandInterpreter(bool bonusEnabled1); // main constructor
	CommandInterpreter(const CommandInterpreter &other) = delete;
	CommandInterpreter(CommandInterpreter &&other) = delete;
	CommandInterpreter &operator=(const CommandInterpreter &other) = delete;
	CommandInterpreter &operator=(CommandInterpreter &&other) = delete;

	friend std::istream &operator>>(std::istream &in, std::vector<std::string> &vec);

private:
	std::string getFullCommand(std::string incCommand);
};

#endif

