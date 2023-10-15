#ifndef _StringCommand_H_
#define _StringCommand_H_


#include <Arduino.h>
#include <cstring>

#include "Command.h"
#include "CommandNoParam.h"
#include "CommandVoid.h"
#include "CommandVoidNoParam.h"


//#define Debug_StringCommand

class StringCommand
{
public:
	StringCommand();
	~StringCommand();

	
	bool AddCommand(char * order, char * (*func)(int argc, char *argv[]), char* help);
	bool AddCommandNoParam(char * order, char * (*func)(), char* help);
	bool AddCommandVoid(char * order, void (*func)(int argc, char *argv[]), char* help);
	bool AddCommandVoidNoParam(char * order, void (*func)(), char* help);


	char * RunCommand(char * order, int argc, char *argv[]);
	char * RunCommand(char * order);
	void RunCommandVoid(char * order, int argc, char *argv[]);
	void RunCommandVoid(char * order);
	
	bool Add(char * order, char * (*func)(int argc, char *argv[]), char* help);
	bool Add(char * order, char * (*func)(), char* help);
	bool Add(char * order, void (*func)(int argc, char *argv[]), char* help);
	bool Add(char * order, void (*func)(), char* help);


	char * Run(char * order, int argc, char *argv[]);
	char * Run(char * order);


private:

	Command * Commands;
	int countCommands;

	CommandNoParam * CommandsNoParam;
	int countCommandsNoParam;

	CommandVoid * CommandsVoid;
	int countCommandsVoid;

	CommandVoidNoParam * CommandsVoidNoParam;
	int countCommandsVoidNoParam;

	bool ExistCommand(char * order, int mode);

};

#endif